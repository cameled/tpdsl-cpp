/***
 * Excerpted from "Language Implementation Patterns",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/tpdsl for more book information.
***/

#include <memory>

#include "Parser.h"
#include "ListLexer.h"

#ifndef __LISTPARSER_H__
#define __LISTPARSER_H__

class ListParser: public Parser {
public:
	ListParser(std::unique_ptr<Lexer> input)
		: Parser(std::move(input)) {

	}

    /** list : '[' elements ']' ; // match bracketed list */
    void list() {
        match(Token::LBRACK); elements(); match(Token::RBRACK);
    }
    /** elements : element (',' element)* ; */
    void elements() {
        element();
        while ( lookahead.type==Token::COMMA ) {
            match(Token::COMMA); element();
        }
    }
    /** element : name | list ; // element is name or nested list */
    void element() {
        if ( lookahead.type==Token::NAME ) match(Token::NAME);
        else if ( lookahead.type==Token::LBRACK ) list();
        else throw "expecting name or list; found " + lookahead.to_string();
    }
};

#endif /* __LISTPARSER_H__ */