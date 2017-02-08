HEADERS = program.h headers.h

all: toc

toc: source/bfcompiler.cpp
	g++ source/bfcompiler.cpp -o toc

clean:
	rm toc
