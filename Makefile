.PHONY: clean, tests

all:
	gcc -std=c23 -o bips32 src/*.c -lcurses -g

clean:
	rm -rf bips32
	rm -rf tests/*.bin

tests:
	cd tests; ./compileall.sh