#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>

//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=37

using namespace std;

struct node {
  int block_num;
  struct node * next;
};
typedef struct node * list;
list blocks[25];
int block_position[25];
int nb;

void insert_block(list a, int pos) {
  list prev = blocks[pos];
  blocks[pos] = a;
  a->next = prev;
  block_position[a->block_num] = pos;
}

struct node * move_blocks_till(int a, int pos_a) {
  list top_a = blocks[pos_a];
  list head = blocks[pos_a];
  list next;
  while (top_a->block_num != a) {
    next = top_a->next;
    insert_block(top_a, top_a->block_num);
    top_a = next;
    head = top_a;
  }
  blocks[pos_a] = head;
  return top_a;
}


void move_over(int a, int b) {
  int pos_a = block_position[a];
  int pos_b = block_position[b];

  if (pos_a == pos_b) return;
  list top_a = move_blocks_till(a, pos_a);
  blocks[pos_a] = top_a->next;
  insert_block(top_a, pos_b);
}

void move_onto(int a, int b) {
  int pos_a = block_position[a];
  int pos_b = block_position[b];

  if (pos_a == pos_b) return;

  list top_a = move_blocks_till(a, pos_a);
  blocks[pos_a] = top_a->next;
  move_blocks_till(b, pos_b);
  insert_block(top_a, pos_b);
}

void pile_over(int a, int b) {
  int pos_a = block_position[a];
  int pos_b = block_position[b];

  if (pos_a == pos_b) return;

  list head = blocks[pos_a];
  list tail = head;
  while (tail->block_num != a) {
    block_position[tail->block_num] = pos_b;
    tail = tail->next;
  }

  block_position[tail->block_num] = pos_b;
  list next = tail->next;
  list prev = blocks[pos_b];
  blocks[pos_b] = head;
  tail->next = prev;
  blocks[pos_a] = next;
}

void pile_onto(int a, int b) {
  int pos_a = block_position[a];
  int pos_b = block_position[b];

  if (pos_a == pos_b) return;

  move_blocks_till(b, pos_b);
  pile_over(a, b);
}

void print() {
  for (int i = 0; i < nb; i++ ) {
    list b = blocks[i];
    cout << i <<":";

    std::vector<int> v;
    while (b)  {
      v.push_back(b->block_num);
      b = b->next;
    }
    for(std::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {
      std::cout << " " <<*it ;
    }
    cout << endl;
  }
}


int main() {

  int a,b;
  cin >> nb;
  string action, what;
  for (int i = 0; i < nb; i++) {
    block_position[i] = i;
    blocks[i] = (list) malloc (sizeof (node));
    blocks[i]->block_num = i;
    blocks[i]->next = NULL;
  }
  cin >> action;
  while (action != "quit") {
    cin >> a;
    cin >> what;
    cin >> b;
    if ( (a > (nb - 1)) || (b > (nb - 1)) ) {
      continue;
    }
    if (a < 0 || b < 0) {
      continue;
    }
    if (action == "move") {
      if (what == "onto") {
        move_onto(a,b);
      }
      else if (what == "over") {
        move_over(a,b);
      }
    }
    else if (action == "pile") {
      if (what == "onto") {
        pile_onto(a,b);
      }
      else if (what == "over") {
        pile_over(a,b);
      }

    }
    cin >> action;
  }

  print();
  return 0;

}



