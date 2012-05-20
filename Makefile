UTIL=lib/*.cc
REVWORDS=examples/revwords.cc

all: revwords 

clean:
	rm -rf run*
	rm -f *.o run*

revwords: $(UTIL) $(REVWORDS)
	gcc -o run-revwords $(UTIL) $(REVWORDS) -g -I/opt/local/include  

.PHONY: all clean
