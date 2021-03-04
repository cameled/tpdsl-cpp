
#ifndef __LISTPARSER_H__
#define __LISTPARSER_H__

#include "Parser.h"

class ListParser: protected Parser {
public:
	ListParser(std::shared_ptr<Lexer> input, size_t lookSize)
		: Parser{input, lookSize} {
	}

	~ListParser() = default;

	void list();

	void elements();

	void element();
};

#endif /* __LISTPARSER_H__ */