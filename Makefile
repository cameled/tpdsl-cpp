
all: lexer

lexer:
	@echo "Build $@"
	make -C parsing/lexer

.PHONY: clean
clean:
	make -C parsing/lexer clean
