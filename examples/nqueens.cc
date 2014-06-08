#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include "utils.h"
using namespace std;

int count;

void construct_candidates(int *a, int k, int n, int *c, int *nc) {

    *nc = 0;
    for (int i = 0; i < n; i++) {
        int is_safe = 1;

        for (int j = 0; j < k; j++) {
            if (a[j] == i) {
                is_safe = 0;
                break;
            }
            if (abs(i - a[j]) == abs(k - j)) {
                is_safe = 0;
                break;
            }
        }

        if (is_safe) {
            c[*nc] = i;
            *nc = *nc + 1;
        }
    }
}

bool is_solution(int *a, int k, int n) {
    return (k == n - 1);
}

void process_solution(int *a, int k, int n) {

    int board[n][n];
    memset(board, 0, sizeof(board));
    for (int i = 0; i < n; i++) {
        board[i][a[i]] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) cout << "X";
            else cout << "O";
        }
        cout << endl;
    }
    cout << endl;
    count++;
}

void backtrack(int *a, int k, int n) {

    if (is_solution(a, k, n))
        process_solution(a, k, n);
    else {
        int c[n];
        int ncand;
        k = k + 1;
        construct_candidates(a, k, n, c, &ncand);
        for (int i = 0; i < ncand; i++) {
            a[k] = c[i];
            backtrack(a, k, n);
        }
    }
}


int main() {

    int n;
    cout << "Enter N: ";
    cin >> n;
    int cols[n];
    count = 0;
    memset(cols, 0, sizeof(cols));
    backtrack(cols, -1, n);
    cout << "Total solutions: " << count;
}
