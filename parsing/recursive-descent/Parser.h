/***
 * Excerpted from "Language Implementation Patterns",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/tpdsl for more book information.
***/

#include <memory>

#include "Lexer.h"
#include "Token.h"

#ifndef __PARSER_H__
#define __PARSER_H__

class Parser {
public:
	Parser(std::unique_ptr<Lexer> input)
		: input{std::move(input)} {
		consume();
	}

	void match(int x) {
		if ( lookahead.type == x) consume();
 		else throw "expecting " + lookahead.getTokenName(x) + 
					"; found " + lookahead.to_string();
	}

	void consume() {
		lookahead = input->nextToken();
	}

protected:
	std::unique_ptr<Lexer> input;
	Token lookahead;
};

#endif /* __PARSER_H__ */