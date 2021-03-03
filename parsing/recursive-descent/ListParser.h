
#ifndef __LISTPARSER_H__
#define __LISTPARSER_H__

#include "Parser.h"

class ListParser: protected Parser {
public:
	ListParser(std::shared_ptr<Lexer> input)
		: Parser{input} {
	}

	~ListParser() = default;

	void list();

	void elements();

	void element();
};

#endif /* __LISTPARSER_H__ */