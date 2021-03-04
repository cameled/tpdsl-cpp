
target=multi

CXX = clang++
CFLAGS += -c -Wall -I./
LDFLAGS =
sources = Test.cpp Token.cpp ListLexer.cpp ListParser.cpp
objs = $(sources:.cpp=.o)

$(target): $(objs)
	$(CXX) $(LDFLAGS) -o $(target) $^

.cpp.o:
	$(CXX) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(target) $(objs)