PROG=smallworld

all:
	g++ -O3 -o $(PROG) s.cpp

clean:
	rm -f $(PROG) $(PROG).tgz

tar:
	tar zcf $(PROG).tgz s.cpp Makefile
