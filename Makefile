
all: lexer recursive

lexer:
	@echo "Build $@"
	make -C parsing/lexer

recursive:
	@echo "Build recursive-descent"
	make -C parsing/recursive-descent

.PHONY: clean
clean:
	make -C parsing/lexer clean
	make -C parsing/recursive-descent clean
