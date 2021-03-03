
#include <sstream>

#include "Token.h"
#include "ListLexer.h"

std::string Token::toString()
{
	std::ostringstream os;
	os << "<\"" << ListLexer::tokenNames[m_type] << "\", " << m_text << ">";
	return os.str();
}