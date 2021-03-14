/***
 * Excerpted from "Language Implementation Patterns",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/tpdsl for more book information.
***/

#ifndef __BACKTRACKPARSER_H__
#define __BACKTRACKPARSER_H__

#include <memory>

#include "Lexer.h"
#include "Parser.h"

class BacktrackParser : public Parser {
public:
	BacktrackParser(std::unique_ptr<Lexer> lexer)
		: Parser(lexer) {
	}

	~BacktrackParser() = default;

	/** 
	 * stat : list EOF | assign EOF ;
	 */
	void stat();
	
	bool speculate_stat_alt1();

	bool speculate_stat_alt2();

	void assign();

	void list();

	void elements();

	void element();
};

#endif /* __BACKTRACKPARSER_H__ */