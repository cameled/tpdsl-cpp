
#ifndef __PARSER_H__
#define __PARSER_H__

#include <vector>

#include "Lexer.h"

class Parser {
public:
	Parser(std::shared_ptr<Lexer> input, size_t lookSize)
		: m_input{input}
		, m_lookSize{lookSize}
		, m_lookaheads{m_lookSize}
		, m_lookIdx{0} {
		try {
			for (size_t i = 0; i < m_lookSize; i++) consume();
		} catch(...) {
			m_input.reset();
			m_lookaheads.clear();
			throw;
		}
	}

	virtual ~Parser() {
		m_input.reset();
		m_lookaheads.clear();
	}

	void consume() {
		m_lookaheads[m_lookIdx] = m_input->nextToken(); // fill next position with token
		m_lookIdx = (++m_lookIdx) % m_lookSize; // increment circular index
	}

	std::shared_ptr<Token> LT(int i) { 
		return m_lookaheads[(m_lookIdx + i - 1) % m_lookSize]; // circular fetch.
	}

	int LA(int i) {
		return LT(i)->getType();
	}

	void match(int x) {
		if (LA(1) == x) consume();
		else {
			std::ostringstream what;
			what << "excepting " << m_input->tokenName(x)
				 << "; found " + LT(1)->toString();
			throw std::logic_error(what.str());
		}
	}

protected:
	std::shared_ptr<Lexer> m_input;
	const size_t m_lookSize;
	std::vector<std::shared_ptr<Token>> m_lookaheads;
	size_t m_lookIdx;
};

#endif /* __PARSER_H__ */