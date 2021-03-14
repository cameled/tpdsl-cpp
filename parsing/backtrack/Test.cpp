
#include <memory>
#include <iostream>

#include "BacktrackLexer.h"
#include "BacktrackParser.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "please input a test string." << std::endl;
		return 0;
	}

	std::unique_ptr<BacktrackLexer> lexer(new BacktrackLexer(argv[1]));
	std::unique_ptr<BacktrackParser> parser(new BacktrackParser(std::move(lexer)));
	try {
		parser->stat();
	} catch (const std::logic_error& ex) {
		std::cout << ex.what() << std::endl;
		return -1;
	}

	return 0;
}