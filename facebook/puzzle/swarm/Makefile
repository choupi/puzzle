PROG=swarm

all:
	g++ -O3 -o $(PROG) s.c

clean:
	rm -f $(PROG) $(PROG).tgz

tar:
	tar zcf $(PROG).tgz s.c Makefile
