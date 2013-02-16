UTIL=lib/*.cc
REVWORDS=examples/revwords.cc
BITMANIP=examples/bitmanip.c
INFIX=examples/infix.cc
SWAPNODES=examples/swapNodes.cc
all: revwords bitmanip infix swapnodes

clean:
	rm -rf run*
	rm -f *.o run*

revwords: $(UTIL) $(REVWORDS)
	gcc -o run-revwords $(UTIL) $(REVWORDS) -g -I/opt/local/include

bitmanip: $(UTIL) $(BITMANIP)
	gcc -o run-bitmanip $(UTIL) $(BITMANIP) -g -I/opt/local/include

infix: $(UTIL) $(INFIX)
	gcc -o run-infix $(UTIL) $(INFIX) -g -I/opt/local/include

swapnodes: $(UTIL) $(SWAPNODES)
	gcc -o run-swapnodes $(UTIL) $(SWAPNODES) -g -I/opt/local/include

.PHONY: all clean
