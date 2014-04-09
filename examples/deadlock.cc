#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include "utils.h"
#include <pthread.h>
using namespace std;

pthread_mutex_t a;
pthread_mutex_t b;

void *t1(void *arg) {
  pthread_mutex_lock(&a);
  cout << "Waiting for lock on b" << endl;
  pthread_mutex_lock(&b);
  cout << "Thread 1" << endl;
  pthread_mutex_unlock(&a);
  pthread_mutex_unlock(&b);
}

void *t2(void *arg) {
  pthread_mutex_lock(&b);
  cout << "Waiting for lock on a" << endl;
  pthread_mutex_lock(&a);

  cout << "Thread 2" << endl;
  pthread_mutex_unlock(&b);
  pthread_mutex_unlock(&a);
}

int main() {

  pthread_t threads[2];

  pthread_create(&threads[0], NULL, t1, NULL);
  pthread_create(&threads[1], NULL, t2, NULL);

  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);

  return 0;
}

