PROG=dancebattle

all:
	g++ -O3 -o $(PROG) d.cpp

clean:
	rm -f $(PROG) $(PROG).tgz

tar:
	tar zcf $(PROG).tgz d.cpp Makefile
