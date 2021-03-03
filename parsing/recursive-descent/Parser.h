
#ifndef __PARSER_H__
#define __PARSER_H__

#include "Lexer.h"

class Parser {
public:
	Parser(std::shared_ptr<Lexer> input)
		: m_input{input}
		, m_lookahead(nullptr) {
	}

	virtual ~Parser() {
		m_input.reset();
		m_lookahead.reset();
	}

	void match(int x) {
		// lazy loading lookahead token.
		if (!m_lookahead) {
			m_lookahead = m_input->nextToken();
		}

		if (m_lookahead->getType() == x) consume();
		else {
			std::ostringstream what;
			what << "excepting " << m_input->tokenName(x)
				 << "; found " + m_lookahead->toString();
			throw std::logic_error(what.str());
		}
	}

	void consume() {
		m_lookahead = m_input->nextToken();
	}

protected:
	std::shared_ptr<Lexer> m_input;
	std::unique_ptr<Token> m_lookahead;
};

#endif /* __PARSER_H__ */