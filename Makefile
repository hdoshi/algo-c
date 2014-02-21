UTIL=lib/*.c*
REVWORDS=examples/revwords.cc
BITMANIP=examples/bitmanip.c
INFIX=examples/infix.cc
SWAPNODES=examples/swapNodes.cc
TOPO=examples/topo.cc
PBTREE=examples/print_btree.cc
INCLUDE=-Iincludes
all: revwords bitmanip infix swapnodes topo pbtree

clean:
	rm -rf run*
	rm -f *.o run*

revwords: $(UTIL) $(REVWORDS)
	g++ -std=c++0x -o run-revwords $(UTIL) $(REVWORDS) -g  $(INCLUDE)

bitmanip: $(UTIL) $(BITMANIP)
	g++ -std=c++0x  -o run-bitmanip $(UTIL) $(BITMANIP) -g  $(INCLUDE)

infix: $(UTIL) $(INFIX)
	g++ -std=c++0x  -o run-infix $(UTIL) $(INFIX) -g  $(INCLUDE)

swapnodes: $(UTIL) $(SWAPNODES)
	g++ -std=c++0x  -o run-swapnodes $(UTIL) $(SWAPNODES) -g  $(INCLUDE)

topo: $(UTIL) $(TOPO)
	g++ -std=c++0x  -o run-topo $(UTIL) $(TOPO) -g $(INCLUDE)

pbtree: $(UTIL) $(PBTREE)
	g++ -std=c++0x  -o run-pbtree $(UTIL) $(PBTREE) -g $(INCLUDE)


.PHONY: all clean
