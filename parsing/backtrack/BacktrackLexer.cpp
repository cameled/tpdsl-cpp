
#include "BacktrackLexer.h"

const int BacktrackLexer::NAME = 2;
const int BacktrackLexer::COMMA = 3;
const int BacktrackLexer::LBRACK = 4;
const int BacktrackLexer::RBRACK = 5;
const int BacktrackLexer::EQUALS = 6;
const std::vector<std::string> BacktrackLexer::tokenNames = {
	"n/a", "<EOF>", "NAME", ",", "[", "]", "="
};

std::unique_ptr<Token> BacktrackLexer::nextToken() {
	while(m_curChar != EOF) {
		switch(m_curChar) {
			case ' ':
			case '\t':
			case '\n':
			case '\r':
			{
				WS();
			}
				break;
			case ',':
			{
				consume(); 
				return std::make_unique<Token>(COMMA, ",");
			}
			case '[':
			{
				consume();
				return std::make_unique<Token>(LBRACK, "[");
			}
			case ']':
			{
				consume();
				return std::make_unique<Token>(RBRACK, "]");
			}
			case '=':
			{
				consume();
				return std::make_unique<Token>(EQUALS, "=");
			}
			default:
			{
				if (isLETTER()) return name();
				else {
					std::ostringstream what;
					what << "Invalid character: " << m_curChar;
					throw std::logic_error(what.str());
				}
			}
		}
	}
	return std::make_unique<Token>(EOF_TYPE, "<EOF>");
}

std::string BacktrackLexer::getTokenName(int type) {
	return tokenNames[type];
}

bool BacktrackLexer::isLETTER() {
	return (m_curChar >= 'a' && m_curChar <= 'z') ||
			(m_curChar >= 'A' && m_curChar <= 'Z');
}

std::unique_ptr<Token> BacktrackLexer::name() {
	std::string buf;
	do {
		buf.push_back(m_curChar);
		consume();
	} while(isLETTER());
	
	return std::make_unique<Token>(NAME, buf);
}

void BacktrackLexer::WS() {
	while (m_curChar == ' ' ||
			m_curChar == '\t' ||
			m_curChar == '\n' ||
			m_curChar == '\r')
		consume();
}


