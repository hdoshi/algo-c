UTIL=lib/*.c*
REVWORDS=examples/revwords.cc
BITMANIP=examples/bitmanip.c
INFIX=examples/infix.cc
SWAPNODES=examples/swapNodes.cc
GRAPH_EX=examples/topo.cc
INCLUDE=-Iincludes
all: revwords bitmanip infix swapnodes graph_ex

clean:
	rm -rf run*
	rm -f *.o run*

revwords: $(UTIL) $(REVWORDS)
	g++  -o run-revwords $(UTIL) $(REVWORDS) -g -I/opt/local/include $(INCLUDE)

bitmanip: $(UTIL) $(BITMANIP)
	g++  -o run-bitmanip $(UTIL) $(BITMANIP) -g -I/opt/local/include $(INCLUDE)

infix: $(UTIL) $(INFIX)
	g++  -o run-infix $(UTIL) $(INFIX) -g -I/opt/local/include $(INCLUDE)

swapnodes: $(UTIL) $(SWAPNODES)
	g++  -o run-swapnodes $(UTIL) $(SWAPNODES) -g -I/opt/local/include $(INCLUDE)
graph_ex: $(UTIL) $(GRAPH_EX)
	g++  -o run-graphex $(UTIL) $(GRAPH_EX) -g $(INCLUDE)

.PHONY: all clean
