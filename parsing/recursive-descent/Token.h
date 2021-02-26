/***
 * Excerpted from "Language Implementation Patterns",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/tpdsl for more book information.
***/

#include <vector>
#include <string>

#ifndef __TOKEN_H__
#define __TOKEN_H__

struct Token {
	static const int EOF_TYPE;
	static const int NAME;
	static const int COMMA;
	static const int LBRACK;
	static const int RBRACK;
	static const std::vector<std::string> tokenNames;

	/* default token value "n/a" */ 
	Token()
		: Token(0, "") {
	}

	Token(int type, std::string text)
		: type{type}
		, text{text} {
	}

	std::string getTokenName(int x) {
		return tokenNames[type];
	}

	std::string to_string() {
		std::string tname = tokenNames[type];
		return "<'" + text + "'," + tname + ">";
	}

	int type;
	std::string text;
};

#endif /* __TOKEN_H__ */