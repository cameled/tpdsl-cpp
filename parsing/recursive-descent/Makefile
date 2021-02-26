
target=recursive-descent

$(target): Test.cpp Token.h Token.cpp Lexer.h ListLexer.h Parser.h ListParser.h
	$(CXX) -o $(target) $^

.PHONY: clean
clean:
	rm -f $(target)