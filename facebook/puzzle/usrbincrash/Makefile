PROG=usrbincrash

all:
	g++ -O3 -o $(PROG) u.cpp

clean:
	rm -f $(PROG) $(PROG).tgz

tar:
	tar zcf $(PROG).tgz u.cpp Makefile
