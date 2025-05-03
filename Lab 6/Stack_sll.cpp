//Stack using singly linked list to perform the functions - Push, Pop, Peek & Exit

#include<stdio.h>
#include<stdlib.h>

class List
{
	private:
		struct node
		{
			char data;
			struct node *next;
		}*top;
	public:
		List()
		{
			top=NULL;
		}
		void push(char);
		char pop();
		char peek();
		int isempty();
};

//Main Function
int main()
{
	int ch,res;
	char val;
	List list;
	printf("\nMenu:\n1:Push\n2:Pop\n3:Peek\n4:Exit");
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	while (ch!=4)
	{
		switch(ch)
		{
			case 1:
				//Push a character into the stack
				printf("Enter the character to be pushed into the stack:");
				scanf(" %c",&val);
				list.push(val);
				break;
			case 2:
				//Pop a character from the stack
				res=list.isempty();
				if (res==1)
				{
					printf("Stack Underflow!\n");
				}
				else
				{
					printf("Character being popped:%c\n",list.pop());
				}
				break;
			case 3:
				//Display the topmost character of the stack(peek)
				res=list.isempty();
				if (res==1)
				{
					printf("Stack Underflow!\n");
				}
				else
				{
					printf("Topmost character:%c\n",list.peek());
				}
				break;
			default:
				printf("Invalid choice!\n");
				break;
		}
		printf("\nMenu:\n1:Push\n2:Pop\n3:Peek\n4:Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
	}
	printf("Exiting!\n");
}

//Function to push a character into the stack
void List::push(char val)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=top;
	top=newnode;
}

//Function to pop a character from the stack
char List::pop()
{
	char res;
	struct node *temp=top;
	res=temp->data;
	top=temp->next;
	free(temp);
	return res;
}

//Function to return the topmost character of the stack(peek)
char List::peek()
{
	char res;
	res=top->data;
	return res;
}

//Function to check if the stack is empty or not
int List::isempty()
{
	if (top==NULL)
	{
		return 1;
	}
	return 0;
}
