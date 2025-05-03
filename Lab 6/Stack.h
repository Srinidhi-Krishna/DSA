// Stack.h
#ifndef STACK_H
#define STACK_H

#include<stdio.h>
#include<stdlib.h>

class Stack
{
	private:
		struct node
		{
			char data;
			struct node *next;
		}*top;
	public:
		Stack()
		{
			top=NULL;
		}
		void push(char);
		char pop();
		char peek();
		int isempty();
};

//Function to push a character into the stack
void Stack::push(char val)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=top;
	top=newnode;
}

//Function to pop a character from the stack
char Stack::pop()
{
	char res;
	struct node *temp=top;
	res=temp->data;
	top=temp->next;
	free(temp);
	return res;
}

//Function to return the topmost character of the stack(peek)
char Stack::peek()
{
	char res;
	res=top->data;
	return res;
}

//Function to check if the stack is empty or not
int Stack::isempty()
{
	if (top==NULL)
	{
		return 1;
	}
	return 0;
}

#endif
