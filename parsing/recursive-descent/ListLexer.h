/***
 * Excerpted from "Language Implementation Patterns",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/tpdsl for more book information.
***/

#include <string>

#include "Lexer.h"

#ifndef __LISTLEXER_H__
#define __LISTLEXER_H__

class ListLexer: public Lexer {
public:
	ListLexer(std::string input)
		:Lexer(input) {
	}

    ~ListLexer() = default;

	bool isLETTER() {
		return (c >= 'a' && c <= 'z') ||
			(c >= 'A' && c <= 'Z');
	}

	Token nextToken() override {
		while ( c!=EOF ) {
            switch ( c ) {
                case ' ': case '\t': case '\n': case '\r':
                    WS();
                    continue;
                case ',' : consume(); return Token(Token::COMMA, ",");
                case '[' : consume(); return Token(Token::LBRACK, "[");
                case ']' : consume(); return Token(Token::RBRACK, "]");
                default:
                    if ( isLETTER() ) return NAMES();
                    throw "invalid character: " + c;
            }
        }
        return Token(Token::EOF_TYPE, "<EOF>");
	}

    /** NAMES : LETTER+ ; // NAMES is sequence of >=1 letter */
    Token NAMES() {
        std::string buf;
        do { buf.push_back(c); LETTER(); } while ( isLETTER() );
        return Token(Token::NAME, buf);
    }

    /** LETTER   : 'a'..'z'|'A'..'Z'; // define what a letter is (\w) */
    void LETTER() {
        if ( isLETTER() ) consume();
        else throw "expecting LETTER; found " + c;
    }

    /** WS : (' '|'\t'|'\n'|'\r')* ; // ignore any whitespace */
    void WS() {
        while ( c==' ' || c=='\t' || c=='\n' || c=='\r' ) consume();
    }
};

#endif /* __LISTLEXER_H__ */