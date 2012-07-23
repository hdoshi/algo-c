UTIL=lib/*.cc
REVWORDS=examples/revwords.cc
BITMANIP=examples/bitmanip.c
INFIX=examples/infix.cc
all: revwords bitmanip infix 

clean:
	rm -rf run*
	rm -f *.o run*

revwords: $(UTIL) $(REVWORDS)
	gcc -o run-revwords $(UTIL) $(REVWORDS) -g -I/opt/local/include  

bitmanip: $(UTIL) $(REVWORDS)
	gcc -o run-bitmanip $(UTIL) $(BITMANIP) -g -I/opt/local/include  

infix: $(UTIL) $(REVWORDS)
	gcc -o run-infix $(UTIL) $(INFIX) -g -I/opt/local/include  
 
.PHONY: all clean
