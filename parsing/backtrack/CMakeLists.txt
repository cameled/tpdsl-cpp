
set(bracktrack_SOURCES)

list(APPEND bracktrack_SOURCES
	BacktrackLexer.cpp
	BacktrackParser.cpp
	Token.cpp
	Test.cpp)

add_executable(backtrack ${bracktrack_SOURCES})
