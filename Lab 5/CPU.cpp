//Round-Robin scheduling algorithm using the Circular Linked List
#include<stdio.h>
#include<stdlib.h>
#include "CPU.h"

int main()
{
    int cpu_time;
    printf("Enter CPU processing time: ");
    scanf("%d", &cpu_time);
    cpu obj(cpu_time);
    int choice;
    int time;
    while (1)
    {
        printf("\n1:Insert Process\n2:Execute\n3:Display\n4:Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        int res;
        if (choice == 1)
        {
            printf("Enter Process Time: ");
            scanf("%d", &time);
            obj.inputprocess(time);
        }
        else if (choice == 2)
        {
            res=obj.execute();
            if(res==-1)
            {
            	printf("No Process!\n");
			}
        }
        else if (choice == 3)
        {
            obj.display();
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
        	printf("Invalid Choice!\n");
		}
    }
    printf("Program Exited\n");
    return 0;
}

