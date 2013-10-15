PROG=breathalyzer

all:
	g++ -O3 -o $(PROG) b.cpp

clean:
	rm -f $(PROG) $(PROG).tgz

tar:
	tar zcf $(PROG).tgz b.cpp Makefile
