UTIL=lib/*.c*
REVWORDS=examples/revwords.cc
BITMANIP=examples/bitmanip.c
INFIX=examples/infix.cc
SWAPNODES=examples/swapNodes.cc
TOPO=examples/topo.cc
INCLUDE=-Iincludes
all: revwords bitmanip infix swapnodes graph_ex

clean:
	rm -rf run*
	rm -f *.o run*

revwords: $(UTIL) $(REVWORDS)
	g++  -o run-revwords $(UTIL) $(REVWORDS) -g  $(INCLUDE)

bitmanip: $(UTIL) $(BITMANIP)
	g++  -o run-bitmanip $(UTIL) $(BITMANIP) -g  $(INCLUDE)

infix: $(UTIL) $(INFIX)
	g++  -o run-infix $(UTIL) $(INFIX) -g  $(INCLUDE)

swapnodes: $(UTIL) $(SWAPNODES)
	g++  -o run-swapnodes $(UTIL) $(SWAPNODES) -g  $(INCLUDE)

topo: $(UTIL) $(topo)
	g++  -o topo $(UTIL) $(GRAPH_EX) -g $(INCLUDE)

.PHONY: all clean
