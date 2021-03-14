
#include "BacktrackLexer.h"
#include "BacktrackParser.h"

void BacktrackParser::stat() {
	// attempt alternative 1: list EOF
	if ( speculate_stat_alt1() ) {
		list(); match(m_lexer->EOF_TYPE);
	}
	// attempt alternative 2: assign EOF
	else if ( speculate_stat_alt2() ) {
		assign(); match(m_lexer->EOF_TYPE);
	} else {
		std::ostringstream oss;
		oss << "exception stat found " << LT(1)->toString();
		throw std::logic_error(oss.str());
	}
}

bool BacktrackParser::speculate_stat_alt1() {
	bool success = true;
	mark(); // mark this spot in input so we can rewind
	try {
		list();
		match(m_lexer->EOF_TYPE);
	} catch (const std::logic_error &e) {
		success = false;
	}
	release(); // either way, rewind to where we were
	return success;
}

bool BacktrackParser::speculate_stat_alt2() {
	bool success = true;
	mark(); // mark this spot in input so we can rewind
	try { 
		assign(); 
		match(m_lexer->EOF_TYPE);
	} catch (const std::logic_error &e) {
		success = false;
	}
	release(); // either way, rewind to where we were
	return success;
}

void BacktrackParser::assign() {
	list();
	match(BacktrackLexer::EQUALS);
	list();
}

void BacktrackParser::list() {
    match(BacktrackLexer::LBRACK);
	elements();
	match(BacktrackLexer::RBRACK);
}

void BacktrackParser::elements() {
	element(); 
	while (LA(1)== BacktrackLexer::COMMA) {
		match(BacktrackLexer::COMMA);
		element();
	}
}

void BacktrackParser::element() {
	if (LA(1) == BacktrackLexer::NAME && LA(2) == BacktrackLexer::EQUALS) {
		match(BacktrackLexer::NAME);
		match(BacktrackLexer::EQUALS);
		match(BacktrackLexer::NAME);
	}
	else if (LA(1) == BacktrackLexer::NAME ) {
		match(BacktrackLexer::NAME);
	} else if (LA(1) == BacktrackLexer::LBRACK ) {
		list();
	} else {
		std::ostringstream what;
		what << "excepting name or list; found " << LT(1)->toString();
		throw std::logic_error(what.str());
	}
}