PROG=fridgemadness

all:
	g++ -O3 -o $(PROG) f.cpp

clean:
	rm -f $(PROG) $(PROG).tgz

tar:
	tar zcf $(PROG).tgz f.cpp Makefile
