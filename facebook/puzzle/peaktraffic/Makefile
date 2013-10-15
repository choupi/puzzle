PROG=peaktraffic

all:
	g++ -O3 -o $(PROG) p.cpp

clean:
	rm -f $(PROG) $(PROG).tgz

tar:
	tar zcf $(PROG).tgz p.cpp Makefile
