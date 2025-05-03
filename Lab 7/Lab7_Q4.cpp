//Program to process a given string

#include<stdio.h>
#include"singlylinkedlist.h"
#include<string.h>

int main()
{
	List list;
	char str[100];
	printf("Enter the string:");
	scanf("%s",str);
	
	//Accessing each character of the string
	for(int i=0;i<strlen(str);i++)
	{
		if (str[i]=='+')
		{
			list.delend();
		}
		else
		{
			list.insertend(str[i]);
		}
	}
	
	list.display();
	return 0;
}


