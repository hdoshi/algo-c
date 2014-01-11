#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/utils.h"


struct QueueNode {
    int capacity;
    void ** elements;
    int head;
    int tail;
};

typedef struct QueueNode * Queue;

Queue queue_create(int cap) {
    Queue s = (Queue) malloc(sizeof(QueueNode));
    s->elements = (void **) malloc(cap * sizeof(void *));
    s->capacity = cap;
    s->head =  -1;
    s->tail = -1;
    return s;
}

int queue_insert(Queue s, void *el) {
    if(s->head != (s->tail + 1) % s->capacity) {
        s->tail = (s->tail + 1) % s->capacity;
        s->elements[(s->tail)] = (void *) el;
        if (s->head < 0 ) s->head = 0;
    }
    else {
        fprintf(stderr, "Queue is full \n");
        return -1;
    }
}

void * queue_delete(Queue s) {
    if (s->head == -1) return NULL;
    if(s->head >= 0) {
        void *f = s->elements[s->head];
        if (s->head == s->tail)
          s->head = s->tail = -1;
        else
          s->head = (s->head + 1) % s->capacity;
        return f;
    }

}

void queue_destroy (Queue s) {
    free(s->elements);
    free(s);
}














