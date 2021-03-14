
target=backtrack

CXX = clang++
CFLAGS += -Wall -I./
HEADERS = Token.h Lexer.h BacktrackLexer.h Parser.h BacktrackParser.h
SOURCES = Test.cpp Token.cpp BacktrackLexer.cpp BacktrackParser.cpp

$(target): $(SOURCES) $(HEADERS)
	$(CXX) $(CFLAGS) $(SOURCES) -o $(target)

.PHONY: clean
clean:
	rm -f $(target)