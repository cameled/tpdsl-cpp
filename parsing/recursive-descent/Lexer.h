/***
 * Excerpted from "Language Implementation Patterns",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/tpdsl for more book information.
***/

#include <string>

#include "Token.h"

#ifndef __LEXER_H__
#define __LEXER_H__

#ifndef EOF
#define EOF (static_cast<char>(-1))
#endif

class Lexer {
public:
	Lexer(std::string input)
		: c{EOF}, p{0}, input{input} {
		if (!this->input.empty()) {
			c = this->input[0];
		}
	}

	virtual ~Lexer() = default;

	void consume() {
		p++;
		if (p >= input.length()) c = EOF;
		else c = input[p];
	}

	void match(char x) {
		if (c = x) consume();
		else throw "expecting " + std::to_string(x) + "; found " + c;
	}

	virtual Token nextToken() = 0;

protected:
	char c;
	int p;
	std::string input;
};

#endif /* __LEXER_H__ */