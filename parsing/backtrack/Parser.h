/***
 * Excerpted from "Language Implementation Patterns",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/tpdsl for more book information.
***/

#ifndef __PARSER_H__
#define __PARSER_H__

#include <sstream>
#include <string>
#include <vector>
#include <memory>

#include "Token.h"
#include "Lexer.h"

class Parser {
public:
	Parser(std::unique_ptr<Lexer> &lexer)
		: m_lexer(std::move(lexer))
		, m_curIdx{0} {
		// start with LL(1).
		fill(1);
	}

	virtual ~Parser() = default;

	void consume() {
		m_curIdx++;
		if (m_curIdx == m_lookheads.size() && !isSpeculating()) {
			m_curIdx = 0;
			m_lookheads.clear();
		}
		sync(1);
	}

	void sync(int i) {
		if (m_curIdx + i - 1 > (m_lookheads.size() - 1)) {
			int n = (m_curIdx+i-1) - (m_lookheads.size() -1);
			fill(n);
		}
	}

	void fill(int n) {
		for (int i = 0; i <= n; i++) {
			m_lookheads.push_back(m_lexer->nextToken());
		}
	}

	std::shared_ptr<Token> LT(int i) {
		sync(i);
		return m_lookheads[m_curIdx+i-1];
	}
	
	int LA(int i) {
		return LT(i)->getType();
	}

	void match(int x) {
		if (LA(1) == x) {
			consume();
		} else {
			std::ostringstream oss;
			oss << "exception " << m_lexer->getTokenName(x)
				<< " found " + LT(1)->toString();
			throw std::logic_error(oss.str());
		}
	}

	int mark() {
		m_markers.push_back(m_curIdx); return m_curIdx;
	}

	void release() {
		if (m_markers.empty())
			return;
	
		int marker = m_markers[m_markers.size() - 1];
		m_markers.pop_back();
		seek(marker);
	}

	void seek(int index) {
		m_curIdx = index;
	}

	bool isSpeculating() {
		return m_markers.size() > 0;
	}

protected:
	std::unique_ptr<Lexer> m_lexer;
	std::vector<int> m_markers;
	std::vector<std::shared_ptr<Token>> m_lookheads;
	int m_curIdx;
};

#endif /* __PARSER_H__ */