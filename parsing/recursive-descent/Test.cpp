
#include <memory>

#include "ListLexer.h"
#include "ListParser.h"

int main(int argc, char *argv[]) {
	std::unique_ptr<ListLexer> lexer = std::make_unique<ListLexer>(argv[1]);
	std::unique_ptr<ListParser> parser = std::make_unique<ListParser>(std::move(lexer));
	parser->list();

	return 0;
}