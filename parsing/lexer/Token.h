
#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>

class Lexer;

class Token
{
public:
	Token(int type, std::string text)
		: m_type(type)
		, m_text(text) {
	}
	~Token() = default;

	int getType() {
		return m_type;
	}

	std::string getText() {
		return m_text;
	}

	std::string toString();

private:
	const int m_type;
	const std::string m_text;
};

#endif /* __TOKEN_H__ */