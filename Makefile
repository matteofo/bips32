.PHONY: clean, tests

all:
	gcc -std=c23 -o bips32 src/*.c -lcurses -g

clean:
	rm -rf bips32
	cd tests; ./clean.sh;
	cd tests/c; ./clean.sh;

tests:
	cd tests; ./compileall.sh
	cd tests/c; ./compileall.sh