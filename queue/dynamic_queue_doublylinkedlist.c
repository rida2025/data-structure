#include <stdio.h>
#include <stdlib.h>

/* Rida style */
typedef struct node {
  int index;
  int value;
  struct node *next;
  struct node *previous;
}Node;

typedef struct queue {
  int size;
  Node *top;
  Node *bottom;
}Queue;

Queue * create_queue(void) {
  Queue * newQueue = (Queue *) malloc(sizeof(Queue));
  newQueue->bottom = NULL;
  newQueue->top = NULL;
  return newQueue;
}

Node* create_node(int val) {
    Node * newNode = malloc(sizeof(Node));
    newNode->value = val;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

void enqueue(Queue * q, int x) {
  Node * newNode = create_node(x);
  printf("enqueue %d\n", x);
  if(q->top == NULL){
    q->top = newNode;
    q->top->index = 0;
    q->bottom = newNode;
    q->bottom->index = 0;
    q->size = 1;
    return;
  }
  newNode->next = q->bottom;
  q->bottom->previous = newNode;
  q->bottom = newNode;
  q->size = q->size + 1;
  int size = q->size - 1;
  q->bottom->index = size;
}

void enqueue_end(Queue * q, int x) {
  Node * newNode = create_node(x);
  printf("enqueue end %d\n", x);
  if(q->top == NULL){
    q->top = newNode;
    q->top->index = 0;
    q->bottom = newNode;
    q->bottom->index = 1;
    q->size = 1;
    return;
  }
  Node* i= q->top;
  while(i != NULL)
  {
      i->index = i->index + 1;
      i = i->previous;
  }
  newNode->next = NULL;
  newNode->previous = q->top;
  q->top->next = newNode;
  q->top = newNode;
  q->top->index = 0;
  q->size = q->size + 1;
  
  free(i);
}

void dequeue(Queue * q) {
    if (q->top == NULL) {
        printf("queue is empty\n");
        return;
    }
    Node* i= q->top;
    while(i != NULL)
    {
      i->index = i->index - 1;
      i = i->previous;
    }
    Node* temp = q->top;
    int value = temp->value;
    q->top = q->top->previous;
    if (q->top == NULL) {
        q->bottom = NULL;
    }
    q->size = q->size - 1;
    free(temp);
    temp = NULL;
    printf("dequeued %d\n", value);
    free(i);
}

void dequeue_end(Queue * q) {
    if (q->bottom == NULL) {
        printf("queue is empty\n");
        return;
    }
    q->size = q->size - 1;
    Node* temp = q->bottom;
    int value = temp->value;
    printf("dequeued end %d\n", value);
    q->bottom = q->bottom->next;
    if (q->bottom != NULL) {
        q->bottom->previous = NULL;
    } else {
        q->top = NULL;
    }
    
    free(temp);
}

void display_queue(Queue* q)
{
    Node* temp = q->top;
    if(q->top == NULL){
        printf("queue is empty\n");
        return;
    }
    printf("queue: ");
    while(temp != NULL){ 
        //printf("[address=%p, value=%d, index=%d, next=%p, previous=%p]->",temp, temp->value, temp->index, temp->next, temp->previous);
        printf("[value=%d, index=%d]->",temp->value, temp->index);
        temp = temp->previous;
    }
    printf("\n");
}

void enqueue_position(Queue* q, int x, int position)
{
    Node * newNode = create_node(x);
    if (q->top == NULL) {
        printf("queue is empty\n");
        return;
    }
    Node* i= q->top;
    position  = position - 1;
    while(i->index != position)
    {
      i = i->previous;
    }
    if(position == 0)
    {
        Node* i= q->top;
      while(i != NULL)
      {
          i->index = i->index + 1;
          i = i->previous;
      }
        
      newNode->next = NULL;
      newNode->previous = q->top;
      q->top->next = newNode;
      q->top = newNode;
      q->top->index = 0;
      q->size = q->size + 1;
      printf("enqueue value:%d in position:0\n", x);
        
      free(i);
    }
    else if(position == q->size-1)
    {
        newNode->next = q->bottom;
        q->bottom->previous = newNode;
        q->bottom = newNode;
        int size = q->size;
        q->bottom->index = position+1;
        printf("enqueue value:%d in position:%d\n", x, position+1);
        q->size = q->size + 1;
        free(i);
    }
    else
    {
        newNode->next = i;
        newNode->previous = i->previous;
        i->previous->next = newNode;
        i->previous = newNode;
        i->previous->index = position+1;
        printf("enqueue value:%d in position:%d\n", x, position+1);
        q->size = q->size + 1;
        Node* a= q->top;
        while(a != NULL)
        {
          a->index = a->index + 1;
          a = a->previous;
        }
        
        free(i);
        free(a);
    }
}
    
void dequeue_position(Queue* q, int position)
{
    if (q->top == NULL) {
        printf("queue is empty\n");
        return;
    }
    Node* i= q->top;
    while(i->index != position)
    {
      i = i->previous;
    }
    if(position == 0)
    {
        printf("dequeue value:%d in position:%d\n", i->value, position);
        q->top = q->top->previous;
        while(i != NULL)
        {
            i->index = i->index - 1;
            i = i->previous;
        }
        free(i);
        q->top->next = NULL;
        q->size = q->size - 1;
        
    }
    else if(position+1 == q->size)
    {
        printf("dequeue value:%d in position:%d\n", i->value, position);
        q->bottom = q->bottom->next;
        q->bottom->previous = NULL;
        free(i);
        q->size = q->size - 1;
    }
    else if(position == i->index)
    {
        printf("dequeue value:%d in position:%d\n", i->value, position);
        Node* a = i;
        while(a != NULL)
        {
            a->index = a->index - 1;
            a = a->previous;
        }
        if(i->next->previous != NULL) i->next->previous = i->previous;
        if(i->previous->next != NULL) i->previous->next = i->next;
        free(i);
        free(a);
        q->size = q->size - 1;
    }
    else
    {
        printf("out of range\n");
    }
    
}

void search_queue(Queue* q, int position)
{
    Node* i= q->top;
    while(i->index != position){
        i = i->previous;
    }
    printf("value=%d\n", i->value);
}

void queue_size(Queue* q)
{
    printf("queue size:%d\n", q->size);
}

int main(void) {
  Queue * queue = create_queue();
  enqueue(queue, 5);
  enqueue(queue, 6);
  enqueue(queue, 7);
  display_queue(queue);
  queue_size(queue);
  enqueue_end(queue, 1);
  display_queue(queue);
  enqueue_position(queue, 9, 1);
  display_queue(queue);
  search_queue(queue, 3);
  dequeue_position(queue, 2);
  display_queue(queue);
  queue_size(queue);
  dequeue(queue);
  display_queue(queue);
  dequeue_end(queue);
  display_queue(queue);
  dequeue(queue);
  display_queue(queue);
  dequeue(queue);
  display_queue(queue);
  
  
  return 0;
}