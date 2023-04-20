#include <stdio.h>
#include <stdlib.h>

int main()
{
	int location = 0;
	int size = 10;
	int *arry;
	int value=0;

	arry = malloc(size * sizeof(int));
	
	while(1)
	{
		int key =0;

		printf("to insert value enter 1 to end the programme enter 2 to show value enter 3: ");
		scanf("%d", &key);
		if(key == 1)
		{
			if(location < size)
			{
				printf("enter value to the array: ");
				scanf("%d", &value);
				arry[location] =  value;
				location++;
			}
			else
			{
				size = size * 2;
				arry = realloc(arry, size * sizeof(int));
			}
			
		}
		else if(key == 2)
		{
			printf("programme is shuting down");
			free(arry);
			break;
		}
		else if(key == 3)
		{
			for (int i = 0; i < location; i++)
			{
				printf("%d ", arry[i]);
			}
			printf("\n");
		}

	}
}