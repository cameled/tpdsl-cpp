
#ifndef __LEXER_H__
#define __LEXER_H__

#include <string>
#include <memory>
#include <sstream>

#include "Token.h"

class Lexer {
public:
	Lexer(std::string &input)
		: m_input{input}
		, cur_idx{0} {
		if (!m_input.empty()) {
			cur_c = m_input.front();
		} else {
			cur_c = EOF;
		}
	}
	virtual ~Lexer() = default;

	virtual std::unique_ptr<Token> nextToken() = 0;
	virtual std::string tokenName(int x) = 0;

	void consume() {
		if ((cur_idx+1) >= m_input.length()) cur_c = EOF;
		else cur_c = m_input[++cur_idx];
	}

	void match(char x) {
		if (cur_c  == x) consume();
		else {
			std::ostringstream what;
			what << "Invalid character:" 
				<< "\ncur_idx = " << std::to_string(cur_idx)
				<< "\ncur_c = " << cur_c 
				<< "\nx = " << x;
			throw std::logic_error(what.str());
		}
	}

public:
#ifndef EOF
	const char EOF = static_cast<char>(-1);
#endif
	const int EOF_TYPE = 1;

protected:
	std::string m_input;
	size_t cur_idx;
	char cur_c;
};

#endif /* __LEXER_H__ */