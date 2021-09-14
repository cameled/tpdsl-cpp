
set(multi_SOURCES)

list(APPEND multi_SOURCES
	ListLexer.cpp
	ListParser.cpp
	Token.cpp
	Test.cpp)

add_executable(multi ${multi_SOURCES})
