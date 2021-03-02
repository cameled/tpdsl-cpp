
target=lexer

$(target): Test.cpp Lexer.h Token.h Token.cpp ListLexer.h ListLexer.cpp
	$(CXX) -o $(target) $^

.PHONY: clean
clean:
	rm -f $(target)