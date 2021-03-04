
#include "ListLexer.h"

const int ListLexer::NAME = 2;
const int ListLexer::COMMA = 3;
const int ListLexer::LBRACK = 4;
const int ListLexer::RBRACK = 5;
const int ListLexer::EQUALS = 6;
const std::vector<std::string> ListLexer::tokenNames = {
	"n/a", "<EOF>", "NAME", "COMMA", "LBRACK", "RBRACK", "=" 
};

std::string ListLexer::tokenName(int x) {
	return tokenNames[x];
}

std::unique_ptr<Token> ListLexer::nextToken() {
	while(cur_c != EOF) {
		switch(cur_c) {
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
				if (isLETTER()) return extractName();
				else {
					std::ostringstream what;
					what << "Invalid character: " << cur_c;
					throw std::logic_error(what.str());
				}
			}
		}
	}
	return std::make_unique<Token>(EOF_TYPE, "<EOF>");
}

bool ListLexer::isLETTER() const {
	return (cur_c >= 'a' && cur_c <= 'z') ||
			(cur_c >= 'A' && cur_c <= 'Z');
}

std::unique_ptr<Token> ListLexer::extractName() {
	std::string buf;
	do {
		buf.push_back(cur_c);
		consume();
	} while(isLETTER());
	
	return std::make_unique<Token>(NAME, buf);
}

void ListLexer::WS() {
	while (cur_c == ' ' ||
			cur_c == '\t' ||
			cur_c == '\n' ||
			cur_c == '\r')
		consume();
}
