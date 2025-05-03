//Circular Linked List - Insert Beginning, Insert End, Insert Position, Delete Beginning, Delete End, Delete Position, Search, Display & Exit

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
        int isempty();
};

//Main function

int main()
{
    List list;
    int ch,num,pos,res1,res2;
    printf("Menu:\n1:Insert Beginning\n2:Insert End\n3:Insert Position\n4:Delete Beginning\n5:Delete End\n6:Delete Position\n7:Search\n8:Display\n9:Exit\n");
    printf("Enter your choice:");
    scanf("%d",&ch);

    while (ch!=9)
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
                
            default:

                printf("Invalid Choice!\n");
                break;
        }

        printf("\nMenu:\n1:Insert Beginning\n2:Insert End\n3:Insert Position\n4:Delete Beginning\n5:Delete End\n6:Delete Position\n7:Search\n8:Display\n9:Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
    }

    printf("Exiting!\n");
    return 0;
}

//Function to insert a number at the beginning of the circular linked list
void List::insertbeg(int num)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    if (head == NULL) 
    {
        newnode->next = newnode; 
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        
        newnode->next = head;  
        temp->next = newnode;  
        head = newnode;        
    }
}

// Function to insert a number at the end of a circular linked list
void List::insertend(int num)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));  
    newnode->data = num;  
    if (head == NULL)  
    {
        newnode->next = newnode;
        head = newnode; 
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}

// Function to insert a number at a given position in a circular linked list
int List::insertpos(int num, int pos)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    if (pos == 0)
    {
        if (head == NULL)  
        {
            head = newnode;
            newnode->next = head; 
        }
        else
        {
            struct node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newnode;  
            newnode->next = head; 
            head = newnode; 
        }
        return 1;
    }

    struct node *temp = head;
    int i = 0;
    while (i < pos - 1 && temp->next != head)
    {
        temp = temp->next;
        i++;
    }
    if (temp->next == head && i < pos - 1)
    {
        return -1;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    
    return 1;
}

// Function to delete an element from the beginning of a circular linked list
int List::delbeg()
{
    int res;
    struct node *temp = head;
    res = temp->data; 
    if (head->next == head)  
    {
        free(head);
        head = NULL;  
        return res;
    }
    struct node *last = head;
    while (last->next != head)  
    {
        last = last->next;
    }
    last->next = head->next;  
    head = head->next; 
    free(temp);  
    return res;  
}

//Function to delete an element from the end of a circular linked list
int List::delend() 
{
	int res;
    if (head->next == head) 
	{ 
        res = head->data;
        free(head);
        head = NULL;  
        return res;   
    }
    struct node* temp = head;
    while (temp->next->next != head) 
	{
        temp = temp->next;
    }
    res = temp->next->data;  
    free(temp->next);  
    temp->next = head; 
    return res;  
}

// Function to delete an element at a given position in a circular linked list
int List::delpos(int pos)
{
    int res;
    if (pos == 0) 
    {
        return delbeg();
	}
    struct node* temp = head;
    struct node* prev = NULL;
    int i = 0;
    while (i < pos && temp->next != head) 
    {
        prev = temp;
        temp = temp->next;
        i++;
    }
    if (i != pos) 
    {
        return -1;  
    }
    res = temp->data;
    if (temp == head) 
    {
        if (head->next == head) 
        {
            free(head);
            head = NULL;  
        }
        else 
        {
            prev = head;
        	while (prev->next != head)
            {
                prev = prev->next;
            }
            prev->next = head->next; 
            free(head);  
            head = head->next;  
        }
    }
    else  
    {
        prev->next = temp->next; 
        free(temp); 
    }

    return res;
}

//Function to search for an element in a singly linked list
int List::search(int num)
{
    int i=0;
    struct node *temp=head;
    do
    {
        if (temp->data == num)
        {    
			return i;
    	}
        temp=temp->next;
        i++;
    } while (temp!= head);
    return -1;
}

//Function to display all the elements of the circular linked list
void List::display()
{
    struct node *temp=head;
    do
    {
        printf("%d  ", temp->data);
        temp=temp->next;
    } while (temp!= head);
    printf("\n");
} 

//Function to check if the circular linked list is empty or not
int List::isempty()
{
    if (head==NULL)
    {
        return 1;
    }
    return 0;
}
