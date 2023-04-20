#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
	int value;
	int size;
	struct queue* previous;
} queue;

queue *qp = NULL;

void enqueue(int x){

    if(qp == NULL)
    {
        qp = malloc(sizeof(queue));
        qp->value = x;
        qp->size = 1;
        qp->previous = NULL;
    }
    else
    {
        queue* current = qp;
        while (current->previous != NULL)
        {
            current = current->previous;
        }
        queue* temp = malloc(sizeof(queue));
        temp->value = x;
        temp->size = current->size + 1;
        temp->previous = NULL;
        current->previous = temp;
    } 
}

void print_queue()
{
    queue* current = qp;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->previous;
    }
}

int main(void)
{
	enqueue(5);
	enqueue(8);
	enqueue(4);
    print_queue();
}