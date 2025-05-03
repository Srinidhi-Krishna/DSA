#include<stdio.h>
#include <string.h>
#include "Stack.h"

// Function to check if the parentheses are balanced or not
int isbalanced(char* expr) 
{
    Stack s;  
    for (int i = 0; expr[i] != '\0'; i++) 
	{
        if (expr[i] == '(') 
		{
            s.push('(');  
        } 
		else if (expr[i] == ')') 
		{
            if (s.isempty()) return 0;  
            s.pop(); 
        }
    }
    return s.isempty(); 
}

// Main function 
int main() 
{
    int ch;
    char str[1000];
    printf("\nMenu:\n1:Check Balance\n2:Exit\n");
    printf("Enter your choice:");
    scanf("%d", &ch);
    while (ch != 2) 
    {
        switch (ch) 
        {
            case 1:
                // To check balanced condition
                printf("Enter a string of parentheses: ");
                scanf("%s", str);
                if (isbalanced(str)) 
                {
                    printf("Balanced number of parentheses!\n");
                } 
                else 
                {
                    printf("Not balanced number of parentheses!\n");
                }
                break;
            default:
                // Invalid choice
                printf("Invalid choice!\n");
                break;
        }
        printf("\nMenu:\n1:Check Balance\n2:Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
    }
    printf("Exiting!\n");
}

