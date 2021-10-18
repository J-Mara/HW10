#include <stdio.h>
#include <stdlib.h>

struct driver_rank{
  char driver_name[200];
  int position;
  struct driver_rank *next;
};

void print_driver(struct driver_rank *d){
  printf("name: %s\tposition: %d\n", (*d).driver_name, d->position);
}

struct driver_rank * make_driver(int i, char c) {
  struct driver_rank *n = malloc(sizeof(struct driver_rank));
  n->position = i;
  n->driver_name[199] = c;
  return n;
}

void print_list(struct driver_rank *h){
  while (h->next != NULL){
    print_driver(h);
    h = h->next;
  }
}

struct driver_rank * insert_front(struct driver_rank *h, char name, int pos){
  struct driver_rank *n = malloc(sizeof(struct driver_rank));
  n->position = pos;
  n->driver_name[199] = name;
  n->next = h;
  return n;
}

struct driver_rank * free_list(struct driver_rank *h ){
  while(h->next != NULL){
    free(h);
    h = h->next;
  }
  return h;
}

int main(){
  struct driver_rank *n = make_driver(1, "Verstappen");
  insert_front(n, "Hamilton", 2);
  print_list(n);
  // printf("weeee\n");
}
