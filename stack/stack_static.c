#include <stdio.h>

int position = -1;

int stack_array[100];

void push(int value)
{
    stack_array[++position] = value;
    printf("%d entered the stack in position %d \n", value, position+1);
}

void pop()
{
    printf("value %d been pop in the position %d \n", stack_array[position], position+1);
    position--;
    stack_array[position];
}

void empty_stack()
{
    while(position != 0)
    {
        stack_array[position--] = 0;
    }
}

void show_stack()
{
    int i=0;
    if(position <= 0)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("the current values in the stack are");
        while(i <= position)
        {
            printf(" %d", stack_array[i]);
            i++;
        }
        printf("\n");
        
    }
}

int main()
{
    push(5);
    push(9);
    push(2);
    show_stack();
    pop();
    push(7);
    show_stack();
    empty_stack();
    show_stack();
    return 0;
}
