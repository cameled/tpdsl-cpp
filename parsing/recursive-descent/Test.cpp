
#include <iostream>

#include "ListLexer.h"
#include "ListParser.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Please input a List." << std::endl;
		return -1;
	}

	std::shared_ptr<ListLexer> lexer(new ListLexer(argv[1]));
	std::shared_ptr<ListParser> parser(new ListParser(lexer));
	try {
		parser->list();
	} catch (const std::logic_error& ex) {
		std::cout << ex.what() << std::endl;
		return -1;
	}

	return 0;
}