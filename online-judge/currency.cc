#include <cstdlib>
#include <iostream>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>

//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=40

using namespace std;


struct res {
  vector<int> path;
  double cost;
};


// paths[i][j][s].cost = max(paths[i][k][1].cost * paths[k][j][s-1].cost, paths[i][j][s].cost)

int main() {
  int previous = 0;
  int n;
  while (cin >> n) {

    if (previous)
      cout << endl;

    previous = 1;

    double w[n][n];
    struct res paths[n + 1][n][n];
    for (int i = 0; i < n; i++) {
      w[i][i] = 1;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if(i == j) continue;
        cin >> w[i][j];
      }
    }

    memset(paths, 0, sizeof(paths));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        paths[0][i][j].cost = 0;
        paths[1][i][j].cost = w[i][j];
        paths[1][i][j].path.push_back(i);
        paths[1][i][j].path.push_back(j);
      }
    }

    for (int steps = 2; steps < n + 1; steps++) {
      for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            if (paths[steps][i][j].cost < paths[1][i][k].cost * paths[steps - 1][k][j].cost) {
              paths[steps][i][j].cost = paths[1][i][k].cost * paths[steps - 1][k][j].cost;
              paths[steps][i][j].path.clear();
              paths[steps][i][j].path.push_back(i);
              //add full path k-j
              paths[steps][i][j].path.insert(paths[steps][i][j].path.end(),paths[steps - 1][k][j].path.begin() ,paths[steps - 1][k][j].path.end());
            }
          }
        }
      }
    }

    int chosen_one = -1;
    int minl = 22;
    for (int i = 0; i < n; i++ ) {
      for (int steps = 2; steps < n + 1; steps++) {
        if (paths[steps][i][i].cost > (double)1.01) {
          if (steps < minl) {
            chosen_one = i;
            minl = steps;
          }
        }
      }
    }

    if (chosen_one != -1) {
      for(std::vector<int>::iterator it = paths[minl][chosen_one][chosen_one].path.begin(); it != paths[minl][chosen_one][chosen_one].path.end(); ++it) {
        std::cout << (*it) + 1 << " ";
      }
    }
    else {
      cout << "no arbitrage sequence exists" ;
    }
  }
  return 0;
}




