//Perform the following functions using Queue ADT - Enqueue, Dequeue, Peek & Exit

#include<stdio.h>
#define size 5

class queue
{
	private:
		int arr[size];
		int front;
		int rear;
	public:
		queue()
		{
			front=-1;
			rear=-1;
		}
		int enqueue(int);
		int dequeue();
		int peek();
};

//Menu Driven Main Function

int main()
{
	int ch,val,result;
	queue q;
	printf("Menu:\n1:Enqueue\n2:Dequeue\n3:Peek\n4:Exit\n");
	printf("Enter your choice:");
	scanf("%d",&ch);
	while (ch!=4)
	{
		switch(ch)
		{
			case 1:
				//Enqueue
				printf("Enter the value to be enqueued:");
				scanf("%d",&val);
				result=q.enqueue(val);
				if (result==0)
				{
					printf("Queue Overflow!\n");
				}
				else
				{
					printf("Operation Successful!\n");
				}
				break;
				
			case 2:
				//Dequeue
				result=q.dequeue();
				if (result==-1)
				{
					printf("Queue is Empty!\n");
				}
				else
				{
					printf("Dequeued element from the queue:%d\n",result);
				}
				break;
				
			case 3:
				//Peek
				result=q.peek();
				if (result==-1)
				{
					printf("Queue is Empty!\n");
				}
				else
				{
					printf("Front element of the queue:%d\n",result);
				}
				break;
				
			default:
				//Invalid Choice
				printf("Invalid Choice!Try again!\n");
				break;
		}
		printf("\nMenu:\n1:Enqueue\n2:Dequeue\n3:Peek\n4:Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
	}
	printf("Exiting!\n");
}

//Function to perform enqueue on the queue
int queue::enqueue(int val)
{
	if(rear==size-1)
	{
		return 0;
	}
	else if(front==-1)
	{
		front=0;
	}
	rear++;
	arr[rear]=val;
	return 1;
}

//Function to perform dequeue on the queue
int queue::dequeue()
{
	if(front==-1 or front>rear)
	{
		return -1;
	}
	int element;
	element=arr[front];
	front++;
	if(front>rear)
	{
		front=rear=-1;
	}
	return element;
}

//Function to display the front element of the queue
int queue::peek()
{
	if(front==-1 or front>rear)
	{
		return -1;
	}
	int element;
	element=arr[front];
	return element;
}
