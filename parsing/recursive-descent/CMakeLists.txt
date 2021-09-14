
set(recurdescent_SOURCES)

list(APPEND recurdescent_SOURCES
	ListLexer.cpp
	ListParser.cpp
	Token.cpp
	Test.cpp)

add_executable(recurdescent ${recurdescent_SOURCES})
