#include <stdio.h>

int queue[100];
int front = 0;
int back = 0;

void Queue(int value){
	queue[front++] = value;
	printf("value %d has been queued successfully\n", value);
}

void Unqueue(){
	printf("unqueued was successfully to value %d\n", queue[back]);
	queue[back++] = 0;
}

void Show_queue(){
	int i=0;
	if(front == 0)
	{
		printf("queue is empty");
	}
	else{
		printf("queue ");
		while(i < front){
			printf("%d ", queue[i]);
			i++; 
		}
		printf("\n");
	}
}

void Empty_queue(){
    while(front != 0)
    {
        queue[front--] = 0;
    }
    printf("queue is empty now\n");
}

int main(void){

	Queue(5);
	Queue(7);
	Queue(2);
	Show_queue();
	Unqueue();
	Show_queue();
	Empty_queue();
	Show_queue();

	return 0;
}