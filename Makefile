
all:
	make -C parsing/recursive-descent

.PHONY: clean
clean:
	make -C parsing/recursive-descent clean