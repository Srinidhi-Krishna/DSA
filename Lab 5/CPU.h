//Header File 
#ifndef CPU_H
#define CPU_H

#include <stdio.h>
#include <stdlib.h>

class cpu
{	
	private:
    struct node
    {
        int process_time;  
        node *next;        
    };
    
    node *head;   
    int cpu_time; 

	public:
    cpu(int cpu_time) 
	{
        this->cpu_time = cpu_time;
        head = NULL;
    }
    void inputprocess(int);
    int execute();
    void display();
    void deletebeg();
};

//Function to add a new process to the list
void cpu::inputprocess(int process_time)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->process_time = process_time;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = newnode;
    }
    else
    {
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newnode->next = head;
        temp->next = newnode;
    }
}

// Function to execute the process 
int cpu::execute()
{
    if (head == NULL)
    {
        return -1;
    }
    node *temp = head;
    temp->process_time = temp->process_time - cpu_time;
    if (temp->process_time > 0)
    {
        head = head->next;
    }
    else
    {
        deletebeg();
    }
    return 1;
}

//Function to display all processes in the list
void cpu::display()
{
    if (head == NULL)
    {
        printf("No Processes\n");
        return;
    }
    printf("Processes:\n");
    node *temp = head;
    do
    {
        printf("%d  ", temp->process_time);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

//Function to delete the first process (beginning of the list)
void cpu::deletebeg() 
{
    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    node *temp2 = head;
    head = head->next;
    temp->next = head;
    free(temp2);
}


#endif // CPU_H
    
