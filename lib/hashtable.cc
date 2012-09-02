#include <stdlib.h>
#include <string.h>

struct node {
    node *next;
    char *key;
    void *value;
};

typedef node** elements;

struct hash {
    elements el;
    int capacity;
};

typedef struct hash * hashtable;


hashtable hash_create(int cap) {
    hashtable h = (hash *)malloc(sizeof(hash));
    h->capacity = cap;
    h->el = (node **)malloc(cap*(sizeof(node *)));
    for (int i = 0; i < cap; i++) {
        h->el[i] = NULL;
    }
}


int get_position(hashtable h, const char *key) {
    int l = strlen(key);
    long int hash = 53851;
    for (int i = 0; i < l; i++) {
        hash = key[i] + (hash << 5 + hash);        
    }    
    int p = hash % (h->capacity);
    return p;
}

int hash_put(hashtable h, const char *key, void *value) {
    int i = get_position(h, key);
    node *current = h->el[i];
    node *previous = NULL;
    while(current) {
        previous = current;
        if(strcmp(current->key, key) == 0) {
            break;
        }
        current = current->next;        
        
    }
    if(!current) {
        current = (node *)malloc(sizeof(node));
    	if(previous) {
	    previous->next = current;
	}
    }
    strncpy(current->key, key, strlen(key));
    current->value = value;    
}


void * hash_get(hashtable h, const char *key) {

    int i = get_position(h, key);
    node *current = h->el[i];
    void *tmp = NULL;
    while(current) {
        if(strcmp(current->key, key) == 0) {
            tmp =  current->value;
        }
        current = current->next;
    }
    return tmp;    
}





