
set(lexer_SOURCES)

list(APPEND lexer_SOURCES
	ListLexer.cpp
	Token.cpp
	Test.cpp)

add_executable(lexer ${lexer_SOURCES})
