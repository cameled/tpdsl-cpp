
#include <memory>
#include <iostream>

#include "ListLexer.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Please input a List." << std::endl;
		return -1;
	}

	std::shared_ptr<ListLexer> lexer(new ListLexer(argv[1]));
	try {
		std::shared_ptr<Token> t = lexer->nextToken();
		while(t->getType() != lexer->EOF_TYPE) {
			std::cout << t->toString() << std::endl;
			t = lexer->nextToken();
		}
		std::cout << t->toString() << std::endl;
	} catch (const std::logic_error& ex) {
		std::cout << ex.what() << std::endl;
		return -1;
	}

	return 0;
}