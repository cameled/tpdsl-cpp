
#include "Token.h"
#include "ListLexer.h"

std::string Token::toString()
{
	return "<\"" + ListLexer::tokenNames[m_type] + "\", " + m_text + ">";
}