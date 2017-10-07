SRCDIR = source
BINDIR = bin
CC     = gcc
MAGICS = brainfuck_as.c
DEST   = runbf
SRC    = /dev/null

.phony: all
all: build

.phony: build
build: $(BINDIR) $(BINDIR)/bf_to_c

$(BINDIR):
	mkdir $@

$(BINDIR)/bf_to_c: source/bfcompiler.cpp
	g++ source/bfcompiler.cpp -o $@

.phony: run
run: build
	$(BINDIR)/bf_to_c $(SRC) $(MAGICS)
	$(CC) $(MAGICS) -o $(DEST)
	rm -rf $(MAGICS)

.phony: clean
clean:
	rm -rf $(BINDIR)
