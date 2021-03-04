
#include "ListParser.h"
#include "ListLexer.h"

void ListParser::list() {
	match(ListLexer::LBRACK);
	elements();
	match(ListLexer::RBRACK);
}

void ListParser::elements() {
	element();
	while (LA(1) == ListLexer::COMMA) {
		match(ListLexer::COMMA);
		element();
	}
}

void ListParser::element() {
	if ( LA(1) == ListLexer::NAME && LA(2) == ListLexer::EQUALS) {
		match(ListLexer::NAME);
		match(ListLexer::EQUALS);
		match(ListLexer::NAME);
	} else if (LA(1) == ListLexer::NAME) {
		match(ListLexer::NAME);
	} else if (LA(1) == ListLexer::LBRACK) {
		list();
	} else {
		std::ostringstream what;
		what << "excepting name or list; found " << LT(1)->toString();
		throw std::logic_error(what.str());
	}
}
