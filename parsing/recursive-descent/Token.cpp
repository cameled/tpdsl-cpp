
#include "Token.h"

const int Token::EOF_TYPE = 1;
const int Token::NAME = 2;
const int Token::COMMA = 3;
const int Token::LBRACK = 4;
const int Token::RBRACK = 5;
const std::vector<std::string> Token::tokenNames = {
	"n/a", "<EOF>", "NAME", "COMMA", "LBRACK", "RBRACK" 
};