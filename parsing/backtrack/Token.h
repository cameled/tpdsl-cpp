
#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>

class Token {
public:
	/**
	 * Constructor of Token
	 * 
	 * @param type token type(define in Lexer).
	 * @param text text info of this token.
	 */
	Token(int type, std::string text);

	/**
	 * generate a string of this token.
	 * 
	 * @return string of this Token.
	 */
	std::string toString();

	/**
	 * token type interface.
	 * 
	 * @return token type.
	 */
	int getType();

	/**
	 * token text interface.
	 * 
	 * @return token text.
	 */
	std::string getText();

private:
	int m_type;
	std::string m_text;
};

#endif /* __TOKEN_H__ */