#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include "Stack.h"

class InfixPostfixEvaluator 
{
    private:
        char infix[100];
        char postfix[100];
    public:
        int precedence(char);
        void infixToPostfix();
        int evaluatePostfix();
        void getInfix();
        void convertInfixToPostfix();
        void evaluatePostfixExpression();
};

int main() {
    InfixPostfixEvaluator obj;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Get Infix\n");
        printf("2. Convert Infix to Postfix\n");
        printf("3. Evaluate Postfix\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                obj.getInfix();
                break;
            case 2:
                obj.convertInfixToPostfix();
                break;
            case 3:
                obj.evaluatePostfixExpression();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, try again!\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to determine precedence of operators
int InfixPostfixEvaluator::precedence(char ch) 
{
    if (ch == '+' || ch == '-') 
    {
        return 1;
    } 
    else if (ch == '*' || ch == '/')
    {
        return 2;
    } 
    else if (ch == '^') 
    {
        return 3;
    }
    return 0;
}

// Function to convert infix expression to postfix
void InfixPostfixEvaluator::infixToPostfix() 
{
    Stack s;
    int k = 0;
    int num = 0;
    
    for (int i = 0; infix[i] != '\0'; i++) 
	{
        char ch = infix[i];
        
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        } 
        else 
		{
            if (num != 0)
			{
                char temp[10];
                sprintf(temp, "%d", num);
                for (int j = 0; temp[j] != '\0'; j++)
				{
                    postfix[k++] = temp[j];
                }
                postfix[k++] = ' ';  
                num = 0;
            }
            
            if (ch == '(') 
			{
                s.push(ch);
            } 
            else if (ch == ')') 
			{
                while (!s.isempty() && s.peek() != '(') 
				{
                    postfix[k++] = s.pop();
                    postfix[k++] = ' '; 
                }
                s.pop(); 
            } 
            else 
			{  
                while (!s.isempty() && 
                      ((ch != '^' && precedence(s.peek()) >= precedence(ch)) || 
                       (ch == '^' && precedence(s.peek()) > precedence(ch)))) 
				{
                    postfix[k++] = s.pop();
                    postfix[k++] = ' ';  
                }
                s.push(ch);
            }
        }
    }

    if (num != 0) 
	{
        char temp[10];
        sprintf(temp, "%d", num);
        for (int j = 0; temp[j] != '\0'; j++) 
		{
            postfix[k++] = temp[j];
        }
        postfix[k++] = ' ';  
    }

    // Pop remaining operators from stack
    while (!s.isempty()) 
	{
        postfix[k++] = s.pop();
        postfix[k++] = ' '; 
    }
    postfix[k] = '\0'; 
}

// Function to evaluate postfix expression
int InfixPostfixEvaluator::evaluatePostfix() 
{
    Stack s;
    int num = 0;
    bool processingNumber = false;

    for (int i = 0; postfix[i] != '\0'; i++) 
    {
        char ch = postfix[i];

        // Handle whitespace as number delimiter
        if (ch == ' ' || ch == '\t') {
            if (processingNumber) {
                s.push(num);  // Push the complete number to stack
                num = 0;      // Reset num for the next number
                processingNumber = false;
            }
            continue;
        }

        // Handle digits (multi-digit numbers)
        if (isdigit(ch)) 
        {
            num = num * 10 + (ch - '0');
            processingNumber = true;
        } 
        // Handle operators
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') 
        {
            // Make sure to push any number being processed
            if (processingNumber) {
                s.push(num);
                num = 0;
                processingNumber = false;
            }
            
            // Need at least two operands for an operation
            if (s.isempty()) {
                printf("Error: Not enough operands for operator %c\n", ch);
                return 0;
            }
            int val2 = s.pop();
            
            if (s.isempty()) {
                printf("Error: Not enough operands for operator %c\n", ch);
                return 0;
            }
            int val1 = s.pop();
            
            int result = 0;
            switch (ch) 
            {
                case '+': 
                    result = val1 + val2; 
                    break;
                case '-': 
                    result = val1 - val2;
                    break;
                case '*': 
                    result = val1 * val2; 
                    break;
                case '/': 
                    if (val2 == 0) {
                        printf("Error: Division by zero\n");
                        return 0;
                    }
                    result = val1 / val2; 
                    break;
                case '^': 
                    result = (int)pow((double)val1, (double)val2); 
                    break;
                default:
                    printf("Error: Unknown operator %c\n", ch);
                    return 0;
            }
            s.push(result);  // Push the result of the operation to the stack
        }
        else {
            printf("Error: Invalid character in expression: %c\n", ch);
            return 0;
        }
    }

    // Handle the last number if any
    if (processingNumber) {
        s.push(num);
    }
    
    // Ensure that there is exactly one result left in the stack
    if (s.isempty()) {
        printf("Error: Empty expression or invalid format\n");
        return 0;
    }
    
    int result = s.pop();
    
    // If there are more values in stack, the expression was invalid
    if (!s.isempty()) {
        printf("Error: Too many operands, invalid expression\n");
        return 0;
    }
    
    return result;  // Final result
}
// Function to get the infix expression
void InfixPostfixEvaluator::getInfix() 
{
    printf("Enter infix expression: ");
    scanf("%s", infix);
}

// Function to display the postfix expression
void InfixPostfixEvaluator::convertInfixToPostfix()
{
    infixToPostfix();
    printf("Postfix expression: %s\n", postfix);
}

// Function to evaluate the postfix expression
void InfixPostfixEvaluator::evaluatePostfixExpression() 
{
    int result = evaluatePostfix();
    printf("Result of postfix evaluation: %d\n", result);
}

