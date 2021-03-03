
#include "ListParser.h"
#include "ListLexer.h"

void ListParser::list() {
	match(ListLexer::LBRACK);
	elements();
	match(ListLexer::RBRACK);
}

void ListParser::elements() {
	element();
	while (m_lookahead->getType() == ListLexer::COMMA) {
		match(ListLexer::COMMA);
		element();
	}
}

void ListParser::element() {
	if (m_lookahead->getType() == ListLexer::NAME) {
		match(ListLexer::NAME);
	} else if (m_lookahead->getType() == ListLexer::LBRACK) {
		list();
	} else {
		std::ostringstream what;
		what << "excepting name or list; found " << m_lookahead->toString();
		throw std::logic_error(what.str());
	}
}
