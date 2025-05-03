//Singly Linked List - Header File

#include<stdio.h>
#include<stdlib.h>

class List
{
    private:
        struct node
        {
            char data;
            struct node *next;
        }*head;
    public:
        //Constructer
        List()
        {
            head=NULL;
        }
        //Deconstructer
        ~List()
        {   
            while (head!=NULL)
            {
                struct node *temp=head;
                head=head->next;
                free(temp);
            }
        }
        void insertend(char);
        void delend();
        void display();
};

//Function to insert a number at the end of the singly linked list
void List::insertend(char num)
{
    struct node *newnode=(struct node*)malloc((sizeof(struct node)));
    newnode->data=num;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

//Function to delete element from the end of the singly linked list
void List::delend()
{
    struct node *temp=head;
    if (temp->next==NULL)
    {
        head=NULL;
    }
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}

//Function to display all the elements in the singly linked list
void List::display()
{
    struct node *temp=head;
    while(temp)
    {
        printf("%c",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

