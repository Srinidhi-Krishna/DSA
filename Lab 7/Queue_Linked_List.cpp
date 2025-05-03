//Perform the following functions using Queue ADT(Linked List) - Enqueue, Dequeue, Peek & Exit

#include<stdio.h>
#include<stdlib.h>

class queue
{
	struct node 
	{
		int data;
		struct node *next;
	}*front,*rear;
	
	public:
		queue()
		{
			front = NULL;
			rear = NULL;
		}
		int enqueue(int);
		int dequeue();
		int peek();
};

//Menu Driven Main Function

int main()
{
	queue q;
	int ch,val,result;
	printf("Menu:\n1:Enqueue\n2:Dequeue\n3:Peek\n4:Exit\n");
	printf("Enter your choice:");
	scanf("%d",&ch);
	while(ch!=4)
	{
		switch(ch)
		{
			case 1:
				//Enqueue
				printf("Enter the number to be enqueued:");
				scanf("%d",&val);
				result=q.enqueue(val);
				if (result==0)
				{
					printf("Memory Allocation Failed!\n");
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
					printf("Dequeued Element:%d\n",result);
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
					printf("Front Element:%d\n",result);
				}
				break;
				
			default:
				//Invalid Choice
				printf("Invalid Choice! Try again!\n");
				break;
		}
		printf("\nMenu:\n1:Enqueue\n2:Dequeue\n3:Peek\n4:Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
	}
	printf("Exiting!\n");
	return 0;
}

//Function to perform enqueue on the queue
int queue::enqueue(int val)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	if (newnode == NULL)
    {
        return 0;
    }
    newnode->data=val;
    newnode->next=NULL;
    if (rear==NULL)
    {
    	front=rear=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
	return 1;
}

//Function to perform dequeue on the queue
int queue::dequeue()
{
	if(front==NULL)
	{
		return -1;
	}
	int element;
	struct node *temp=front;
	element=temp->data;
	front=front->next;
	free(temp);
	if (front==NULL)
	{
		rear=NULL;
	}
	return element;
}

//Function to display the front element of the queue
int queue::peek()
{
	if(front==NULL)
	{
		return -1;
	}
	return front->data;
}
