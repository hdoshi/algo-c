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

bool condition_a = false;
bool condition_b = false;
bool condition_c = false;

pthread_mutex_t mutex_a;
pthread_mutex_t mutex_b;
pthread_mutex_t mutex_c;

pthread_cond_t cond_a = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_b = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_c = PTHREAD_COND_INITIALIZER;

void *a(void *arg) {
  while (1) {
    pthread_mutex_lock(&mutex_a);
    while (condition_a ==false)
      pthread_cond_wait(&cond_a, &mutex_a);
    condition_a = false;
    pthread_mutex_unlock(&mutex_a);

    cout << "Running A" << endl;

    pthread_mutex_lock(&mutex_b);
    pthread_cond_signal(&cond_b);
    condition_b = true;
    pthread_mutex_unlock(&mutex_b);
  }

}

void *b(void *arg) {
  while (1) {
    pthread_mutex_lock(&mutex_b);
    while (condition_b ==false)
      pthread_cond_wait(&cond_b, &mutex_b);
    condition_b = false;
    pthread_mutex_unlock(&mutex_b);

    cout << "Running B" << endl;

    pthread_mutex_lock(&mutex_c);
    condition_c = true;
    pthread_cond_signal(&cond_c);
    pthread_mutex_unlock(&mutex_c);
  }
}

void *c(void *arg) {
  while (1) {
    pthread_mutex_lock(&mutex_c);
    while (condition_c == false)
      pthread_cond_wait(&cond_c, &mutex_c);
    condition_c = false;
    pthread_mutex_unlock(&mutex_c);

    cout << "Running C" << endl;

    pthread_mutex_lock(&mutex_a);
    condition_a = true;
    pthread_cond_signal(&cond_a);
    pthread_mutex_unlock(&mutex_a);
  }
}

int main() {

  pthread_t threads[3];

  pthread_create(&threads[0], NULL, a, NULL);
  pthread_create(&threads[1], NULL, b, NULL);
  pthread_create(&threads[2], NULL, c, NULL);

  pthread_mutex_lock(&mutex_a);
  condition_a = true;
  pthread_cond_signal(&cond_a);
  pthread_mutex_unlock(&mutex_a);
  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);
  pthread_join(threads[2], NULL);

  return 0;
}

