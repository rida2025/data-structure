#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int value;
    int size;
    struct stack* next;

} Stack;

Stack *sp = NULL;

void push(int val)
{
    Stack *ptr = malloc(sizeof(Stack));
    if(sp == NULL){
        ptr->value = val;
        ptr->next = NULL;
        ptr->size = 1;
        sp = ptr;
    }
    else{
        ptr->value = val;
        ptr->next = sp;
        ptr->size = ptr->size + 1;
        sp = ptr;
    }
}

void pop()
{
    if(sp == NULL)
    {
        printf("stack is empty");
    }
    int x = sp->value;
    Stack* temp = sp;
    sp = sp->next;
    free(temp);
    if(sp != NULL){
        sp->size = sp->size -1;
    }
    printf("%d was freed\n", x);
}

void peek()
{
    if(sp == NULL)
    {
        printf("stack is empty");
    }
    int x = sp->value;
    printf("%d is in the top of stack\n", x);
}

void show_stack()
{
    if(sp == NULL)
    {
        printf("stack is empty");
    }
    else{
        for(Stack *i=sp;i != NULL;i= i->next)
        {
            printf("%d ", i->value);
        }
    }
    printf("\n");
}

int main(void)
{
    push(5);
    push(8);
    push(4);
    pop();
    peek();
    show_stack();

    return 0;
}