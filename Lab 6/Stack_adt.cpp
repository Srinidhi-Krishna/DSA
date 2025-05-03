//Stack ADT - Push, Pop, Peek & Exit

#include<stdio.h>
#define len 5

class Stack
{
	private:
		char arr[len];
		int top;
	public:
		Stack()
		{
			top=-1;
		}
		void push(char);
		char pop();
		char peek();
		int isfull();
		int isempty();
};

//Main Function
int main()
{
	int ch,res;
	char val;
	Stack stack;
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
				res=stack.isfull();
				if(res==1)
				{
					printf("Stack Overflow!\n");
				}
				else
				{
					stack.push(val);
				}
				break;
			case 2:
				//Pop a character from the stack
				res=stack.isempty();
				if (res==1)
				{
					printf("Stack Underflow!\n");
				}
				else
				{
					printf("Character being popped:%c\n",stack.pop());
				}
				break;
			case 3:
				//Display the topmost character of the stack(peek)
				res=stack.isempty();
				if (res==1)
				{
					printf("Stack Underflow!\n");
				}
				else
				{
					printf("Topmost character:%c\n",stack.peek());
				}
				break;
			default:
				//Invalid choice
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
void Stack::push(char val)
{
	top++;
	arr[top]=val;
}

//Function to pop a character from the stack
char Stack::pop()
{
	char res;
	res=arr[top];
	top--;
	return res;
}

//Function to return the topmost character of the stack(peek)
char Stack::peek()
{
	char res;
	res=arr[top];
	return res;
}

//Function to check if the stack is full or not
int Stack::isfull()
{
	if (top==len-1)
	{
		return 1;
	}
	return 0;
}

//Function to check if the stack is empty or not
int Stack::isempty()
{
	if (top==-1)
	{
		return 1;
	}
	return 0;
}
