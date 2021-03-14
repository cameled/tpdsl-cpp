
#ifndef __LEXER_H__
#define __LEXER_H__

#include <sstream>
#include <string>
#include <memory>

#include "Token.h"

class Lexer {
public:
	Lexer(std::string input)
		: m_input{input}
		, m_curIdx{0} {
		if (!m_input.empty()) {
			m_curChar = m_input[m_curIdx++];
		} else {
			m_curChar = EOF;
		}
	}

	virtual ~Lexer() = default;

	/**
	 * Move to next character.
	 */
	void consume() {
		if ((m_curIdx + 1) > m_input.length()) {
			m_curChar = EOF;
		} else {
			m_curChar = m_input[m_curIdx++];
		}
	}

	/**
	 * Ensure x is next character on the input stream.
	 */
	void match(char x) {
		if (m_curChar == x) {
			consume();
		} else {
			std::ostringstream oss;
			oss << "excepting " << x
			    << "; found " << m_curChar;
			throw std::logic_error(oss.str());
		}
	}

	/**
	 * get next token from input.
	 * 
	 * @return next token.
	 */
	virtual std::unique_ptr<Token> nextToken() = 0;

	/**
	 * get token name.
	 * 
	 * @param token type.
	 * @return token name.
	 */
	virtual std::string getTokenName(int type) = 0;


#ifndef EOF
	const char EOF = (char)-1;
#endif
	const int EOF_TYPE = 1;

protected:
	std::string m_input;
	int m_curIdx;
	char m_curChar;
};

#endif /* __LEXER_H__ */