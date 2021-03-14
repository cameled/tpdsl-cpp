/***
 * Excerpted from "Language Implementation Patterns",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/tpdsl for more book information.
***/

#ifndef __BACKTRACKLEXER_H__
#define __BACKTRACKLEXER_H__

#include <vector>
#include <string>

#include "Lexer.h"

class BacktrackLexer: public Lexer {
public:
    static const int NAME;
    static const int COMMA;
    static const int LBRACK;
    static const int RBRACK;
    static const int EQUALS;
	static const std::vector<std::string> tokenNames;

	BacktrackLexer(std::string input)
		: Lexer(input) {	
	}
	
	~BacktrackLexer() = default;

	std::unique_ptr<Token> nextToken() override;
	std::string getTokenName(int type) override;

private:
	bool isLETTER();

	/**
	 * name : (a'..'z'|'A'..'Z')+ ; // name is sequence of >=1 letter
	 */
	std::unique_ptr<Token> name();

	/**
	 * WS : (' '|'\t'|'\n'|'\r')* ; // ignore any whitespace
	 */
	void WS();
};

#endif /* __BACKTRACKLEXER_H__ */