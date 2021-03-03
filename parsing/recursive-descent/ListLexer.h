
#ifndef __LISTLEXER_H__
#define __LISTLEXER_H__

#include <vector>
#include <string>

#include "Lexer.h"
#include "Token.h"

class ListLexer
	: public Lexer
	, public std::enable_shared_from_this<ListLexer> {
public:
	static const int NAME;
	static const int COMMA;
	static const int LBRACK;
	static const int RBRACK;
	static const std::vector<std::string> tokenNames;

	ListLexer(std::string input)
		: Lexer(input) {
	}
	~ListLexer() = default;

	std::unique_ptr<Token> nextToken() override;
	std::string tokenName(int x) override;
	
private:
	bool isLETTER() const;
	/** extractName : ('a'..'z'|'A'..'Z')+; // NAME is sequence of >=1 letter */
	std::unique_ptr<Token> extractName();
    /** WS : (' '|'\t'|'\n'|'\r')* ; // ignore any whitespace */
	void WS();	
};


#endif /* __LISTLEXER_H__*/