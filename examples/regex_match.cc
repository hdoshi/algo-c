#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "utils.h"
using namespace std;

void dfs(graph g, int start, unordered_map<int, bool> &marked) {

    vertex v = g->vertices[start];
    while (v) {
        if (marked.find(v->v) == marked.end()) {
            marked[v->v] = true;
            dfs(g, v->v, marked);
        }
        v = v->next;
    }
}

unordered_map<int, bool> dfs_vertices(graph g, vector<int> s) {
    unordered_map<int, bool> marked;
    for (int i = 0; i < s.size(); i++) {
        dfs(g, s[i], marked);
    }
    return marked;
}

void build_nfa(graph g, string re) {
    size_t len = re.length();
    for (size_t i = 0; i < len; i++) {

        int l = i;

        if (i < len - 1 && re[i + 1] == '*') {
            add_edge(g, l, i + 1);
            add_edge(g, i + 1, l);
        }

        if (re[i] == '*')
            add_edge(g, i, i + 1);

    }
}


bool match(string in, string re) {
    graph nfa = create_graph(re.length() + 1);
    build_nfa(nfa, re);

    size_t len = in.length();
    unordered_map<int, bool> marked = dfs_vertices(nfa, {0});

    vector<int> start;
    size_t re_len = re.length();
    for (size_t i = 0; i <= re_len; i++) {
        if (marked.find(i) != marked.end()) start.push_back(i);
    }
    for (size_t i = 0; i < len; i++) {
        vector<int> states;
        for (size_t j = 0; j < start.size(); j++) {
            int v = start[j];
            if (v < re_len  && (re[v] == in[i] || re[v] == '.')) {
                states.push_back(v + 1);
            }
        }
        marked = dfs_vertices(nfa, states);
        start.clear();
        for (size_t k = 0; k <= re_len; k++) {
            if (marked.find(k) != marked.end()) start.push_back(k);
        }
    }

    for (size_t i = 0; i < start.size(); i++) {
        if (start[i] == re_len) return true;
    }

    return false;
}


int main() {
    cout << match("ab" , "ab*") << endl;
    cout << match("ab" , "ac*") << endl;
    cout << match("ad" , "ab*d") << endl;
    cout << match("ad" , "abd") << endl;
    cout << match("ad" , ".*") << endl;
}
