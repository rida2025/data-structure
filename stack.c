#include stdio.h

int position = -1;

int stack_array[100];

void push(int value)
{
    stack_array[++position] = value;
    printf(%d entered the stack in position %d n, value, position);
}

void pop()
{
    stack_array[position] = '0';
}

void empty_stack()
{
    while(position = 0)
    {
        stack_array[position--] = 0;
    }
}

void show_stack()
{
    int i=0;
    if(position = 0)
    {
        printf(stack is emptyn);
    }
    else
    {
        printf(the current values in the stack are);
        while(i = position)
        {
            printf( %d, stack_array[i]);
            i++;
        }
        printf(n);
        
    }
}

int main()
{
    push(5);
    push(9);
    push(2);
    show_stack();
    pop();
    show_stack();
    empty_stack();
    show_stack();
    
    
    printf(...);

    return 0;
}
