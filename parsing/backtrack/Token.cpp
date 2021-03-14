
#include <sstream>

#include "Token.h"
#include "BacktrackLexer.h"

Token::Token(int type, std::string text)
	: m_type{type}
	, m_text{text} {
}

std::string Token::toString() {
	std::ostringstream oss;
	oss << "<'" << m_text
		<< "'," << BacktrackLexer::tokenNames[m_type]
		<< ">";
	
	return oss.str();
}

int Token::getType() {
	return m_type;
}

std::string Token::getText() {
	return m_text;
}
