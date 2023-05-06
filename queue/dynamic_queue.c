#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

Queue* create_queue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void enqueue(Queue* queue, int value) {
    Node* new_node = create_node(value);
    if (queue->tail == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        new_node->prev = queue->tail;
        queue->tail->next = new_node;
        queue->tail = new_node;          
    }
    printf("enqueue %d\n", value);
}

void dequeue(Queue* queue) {
    if (queue->head == NULL) {
        printf("Queue is empty.\n");
    }
    Node* temp = queue->head;
    int value = temp->value;
    queue->head = temp->next;
    if (queue->head != NULL) {
        queue->head->prev = NULL;
    } else {
        queue->tail = NULL;
    }
    free(temp);
    printf("Dequeued value: %d\n", value);
}

void show_queue(Queue* queue) {
    Node* temp = queue->head;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void enqueue_end(Queue* queue, int value) {
    Node* new_node = create_node(value);
    if (queue->head == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        new_node->next = queue->head;
        queue->head->prev = new_node;
        queue->head = new_node;
    }
}

void dequeue_end(Queue* queue) {
    if (queue->tail == NULL) {
        printf("Queue is empty.\n");
    }
    Node* temp = queue->tail;
    int value = temp->value;
    queue->tail = temp->prev;
    if (queue->tail != NULL) {
        queue->tail->next = NULL;
    } else {
        queue->head = NULL;
    }
    free(temp);
    printf("Dequeued the last value: %d\n", value);
}

int main() {
    Queue* queue = create_queue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue_end(queue, 0);
    show_queue(queue);

    dequeue(queue);
    
    show_queue(queue);

    dequeue_end(queue);
    show_queue(queue);
    free(queue);
    return 0;
}
