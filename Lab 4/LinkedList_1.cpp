//Singly Linked List - Insert Beginning, Insert End, Insert Position, Delete Beginning, Delete End, Delete Position, Search, Display, Display Reverse, Reverse Link & Exit

#include<stdio.h>
#include<stdlib.h>

class List
{
    private:
        struct node
        {
            int data;
            struct node *next;
        } *head;
    public:
        //Construction
        List()
        {
            head=NULL;
        }
        //Deconstruction
        ~List()
        {
            while (head!=NULL)
            {
                struct node *temp=head;
                head=head->next;
                free(temp);
            }
        }

        void insertbeg(int num);
        void insertend(int num);
        int insertpos(int num,int pos);
        int delbeg();
        int delend();
        int delpos(int pos);
        int search(int num);
        void display();
        void disprev();
        void rev();
        void swap(int a, int b);
        int isempty();
};

//Main function

int main()
{
    List list;
    int ch,num,pos,res1,res2;
    printf("Menu:\n1:Insert Beginning\n2:Insert End\n3:Insert Position\n4:Delete Beginning\n5:Delete End\n6:Delete Position\n7:Search\n8:Display\n9:Display Reverse\n10:Reverse Link\n11:Exit\n");
    printf("Enter your choice:");
    scanf("%d",&ch);

    while (ch!=11)
    {
        switch (ch)
        {
            case 1:

                //Insert Beginning
                printf("Enter the number to be inserted at the beginning:");
                scanf("%d",&num);
                list.insertbeg(num);
                break;

            case 2:

                //Insert End
                printf("Enter the number to be inserted at the end:");
                scanf("%d",&num);
                list.insertend(num);
                break;

            case 3:

                //Insert Position
                printf("Enter the number to be at the given position:");
                scanf("%d",&num);
                printf("Enter the position where the number is to be inserted:");
                scanf("%d",&pos);
                if (pos<0)
                {
                    printf("Invalid Position!\n");
                }
                else
                {
                    res2=list.insertpos(num,pos);
                    if(res2==-1)
                    {
                        printf("Invalid Position!\n");
                    }
                }
                break;

            case 4:

                //Delete Beginning
                res1=list.isempty();
                if (res1==1)
                {
                    printf("List is empty!\n");
                }
                else
                {
                    res2=list.delbeg();
                    printf("The element deleted from the beginning:%d\n",res2);
                }
                break;

            case 5:

                //Delete End
                res1=list.isempty();
                if (res1==1)
                {
                    printf("List is empty!\n");
                }
                else
                {
                    res2=list.delend();
                    printf("The element deleted from the end:%d\n",res2);
                }
                break;

            case 6:

                //Delete Position
                printf("Enter the position where the number is to be deleted:");
                scanf("%d",&pos);
                res1=list.isempty();
                if (res1==1)
                {
                    printf("List is empty!\n");
                }
                else
                {
                    if (pos<0)
                    {
                        printf("Invalid Position!\n");
                    }
                    else
                    {
                        res2=list.delpos(pos);
                        if(res2==-1)
                        {
                            printf("Invalid Position!\n");
                        }
                        else
                        {
                            printf("The element deleted at the position %d:%d\n",pos,res2);
                        }
                    }
                }
                break;

            case 7:

                //Search
                printf("Enter the number to be searched:");
                scanf("%d",&num);
                res1=list.isempty();
                if (res1==1)
                {
                    printf("List is empty!\n");
                }
                else
                {
                    res2=list.search(num);
                    if(res2==-1)
                    {
                        printf("The element %d is not present in the given list!\n",num);
                    }
                    else
                    {
                        printf("The element %d is present at the position:%d\n",num,res2);
                    }    
                }               
                break;

            case 8:

                //Display
                res1=list.isempty();
                if (res1==1)
                {
                    printf("List is empty!\n");
                }
                else
                {
                    printf("The elements in the list are :");
                    list.display();
                }
                break;

            case 9:

                //Display Reverse
                res1=list.isempty();
                if (res1==1)
                {
                    printf("List is empty!\n");
                }
                else
                {
                    printf("The elements in the list in reverse order are :");
                    list.disprev();
                }
                break;

            case 10:

                //Reverse Link
                res1=list.isempty();
                if (res1==1)
                {
                    printf("List is empty!\n");
                }
                else
                {
                    list.rev();
                }
                break;

            default:

                printf("Invalid Choice!\n");
                break;
        }

        printf("\nMenu:\n1:Insert Beginning\n2:Insert End\n3:Insert Position\n4:Delete Beginning\n5:Delete End\n6:Delete Position\n7:Search\n8:Display\n9:Display Reverse\n10:Reverse Link\n11:Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
    }

    printf("Exiting!\n");
    return 0;
}

//Function to insert a number at the beginning of the singly linked list
void List::insertbeg(int num)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    head=newnode;
}

//Function to insert a number at the end of the singly linked list
void List::insertend(int num)
{
    struct node *newnode=(struct node*)malloc(int(sizeof(struct node)));
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

//Function to insert a number at a given position in a singly linked list
int List::insertpos(int num, int pos)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    if (pos==0)
    {
        newnode->next=head;
        head=newnode;
        return 1;
    }
    struct node *temp=head;
    for(int i=0;temp&&i<pos-1;i++)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        return -1;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return 1;
}

//Fuction to delete an element from the beginning of the singly linked list
int List::delbeg()
{
    struct node *temp=head;
    head=head->next;
    return temp->data;
    free(temp);
}

//Function to delete an element from the end of the singly linked list
int List::delend()
{
    int res;
    struct node *temp=head;
    if(temp->next==NULL)
    {
        res=temp->data;
        head=NULL;
        return res;
    }
    
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    res=temp->next->data;
    temp->next=NULL;
    return res;
}

//Function to delete an element at a given position in a singly linked list
int List::delpos(int pos)
{
    int res;
    struct node *temp=head;
    if (pos==0)
    {
        head=head->next;
        res=temp->data;
        return res;
    }
    struct node *prev=head;
    for(int i=0;temp&&i<pos;i++)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        return -1;
    }
    prev->next=temp->next;
    res=temp->data;
    return res;
    free(temp);
}

//Function to search for an element in a singly linked list
int List::search(int num)
{
    int i=0;
    struct node *temp=head;
    while (temp)
    {
        if(temp->data==num)
        {
            return i;
        }
        temp=temp->next;
        i++;
    }
    return -1;
}

//Function to display all the elements of the singly linked list
void List::display()
{
    struct node *temp=head;
    while(temp)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");
} 

//Function to display all the elements of the singly linked list in reverse order
void List::disprev()
{
    int size=0;
    struct node *temp=head;
    while(temp)
    {
        temp=temp->next;
        size++;
    }
    for(int i=0;i<size;i++)
    {
        temp=head;
        int k=size-i-1;
        for (int j=0;j<k;j++)
        {
            temp=temp->next;
        }
        printf("%d  ",temp->data);
    }
    printf("\n");
}

//Function to reverse the link of the singly linked list
void List::rev()
{
    int size=0;
    struct node *temp=head;
    while(temp)
    {
        temp=temp->next;
        size++;
    }
    int mid=size/2;
    for(int i=0;i<mid;i++)
    {
        int j=size-i-1;
        swap(i,j);
    }
}

//Function to swap two numbers of a singly linked list
void List::swap(int a, int b)
{
    struct node *ptr1=head;
    struct node *ptr2=head;
    for(int i=0;i<a;i++)
    {
        ptr1=ptr1->next;
    }
    for(int j=0;j<b;j++)
    {
        ptr2=ptr2->next;
    }
    int temp=ptr1->data;
    ptr1->data=ptr2->data;
    ptr2->data=temp;
}

//Function to check if the singly linked list is empty or not
int List::isempty()
{
    if (head==NULL)
    {
        return 1;
    }
    return 0;
}
