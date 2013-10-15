PROG=gattaca
CODE=g.c

all:
	g++ -o $(PROG) $(CODE)

clean:
	rm -f $(PROG) $(PROG).tgz

tar:
	tar zcf $(PROG).tgz $(CODE) Makefile
