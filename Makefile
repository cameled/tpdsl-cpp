
all: lexer recursive multi backtrack

lexer:
	@echo "Build $@"
	make -C parsing/lexer

recursive:
	@echo "Build recursive-descent"
	make -C parsing/recursive-descent

multi:
	@echo "Build multi"
	make -C parsing/multi

backtrack:
	@echo "Build backtrack"
	make -C parsing/backtrack

.PHONY: clean
clean:
	make -C parsing/lexer clean
	make -C parsing/recursive-descent clean
	make -C parsing/multi
	make -C parsing/backtrack
