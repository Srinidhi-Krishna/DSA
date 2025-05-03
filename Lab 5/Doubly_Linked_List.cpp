//Doubly Linked List - Insert Beginning, Insert End, Insert Position, Delete Beginning, Delete End, Delete Position, Search, Display & Exit

#include<stdio.h>
#include<stdlib.h>

class List
{
    private:
        struct node
        {
            int data;
            struct node *prev;
            struct node *next;
        } *head,*tail;
    public:
        //Construction
        List()
        {
            head=NULL;
            tail=NULL;
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
            
            while (tail!=NULL)
            {
            	struct node *temp=tail;
            	tail=tail->prev;
            	free(temp);
			}
            
        }

        void insertbeg(int);
        void insertend(int);
        int insertpos(int,int);
        int delbeg();
        int delend();
        int delpos(int);
        int search(int);
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

//Function to insert a number at the beginning of the doubly linked list
void List::insertbeg(int num)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=head;
    newnode->prev=NULL;     
    if (head!=NULL)
    {
        head->prev=newnode;
    }
    else
    {
        tail=newnode;
    }
    head=newnode;
}

//Function to insert a number at the end of the doubly linked list
void List::insertend(int num)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    newnode->prev=tail;
    if (tail!=NULL)
    {
        tail->next=newnode;
    }
    else
    {
        head=newnode;
    }
    tail=newnode;
}

//Function to insert a number at a given position in a doubly linked list
int List::insertpos(int num, int pos)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    if (pos == 0)  
    {
        newnode->prev = NULL;
        newnode->next = head;
        if (head != NULL)
        {
            head->prev = newnode;
        }
		else
        {
        	tail = newnode;  
        }
		head = newnode;
        return 1;
    }
    struct node *temp = head;
    for (int i = 0; temp && i < pos-1; i++)
    {
        temp = temp->next;
    }
    
    if (temp == NULL)  
    {
        return -1;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next == NULL) 
    {
	    tail = newnode;
    }
	else
    {
	    temp->next->prev = newnode;
	}
    temp->next = newnode;
    return 1;
}

//Fuction to delete an element from the beginning of the doubly linked list
int List::delbeg()
{
    struct node *temp=head;
    head=head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    else
    {
        tail = NULL;
    }
    return temp->data;
    free(temp);
}

//Function to delete an element from the end of the doubly linked list
int List::delend()
{
    int res;
    struct node *temp=tail;
    res=temp->data;
    tail=tail->prev;
    if (tail!=NULL)
    {
        tail->next=NULL;
    }
    else
    {
        head=NULL; 
    }
    free(temp);
    return res;
}

//Function to delete an element at a given position in a doubly linked list
int List::delpos(int pos)
{
    int res;
    struct node *temp = head;
    
    if (pos==0)
    {
        if (head==NULL) 
        {
		    return -1;
    	}
        head=head->next;
        if (head != NULL)
        {
		    head->prev = NULL;
        }
		else
        {
		    tail = NULL;  
    	}
        res = temp->data;
        free(temp);
        return res;
    }
    for (int i = 0; temp && i < pos; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)  
    {
        return -1;
	}
    temp->prev->next = temp->next;
    if (temp->next != NULL)  
    {
        temp->next->prev = temp->prev;
    }
	else
    {
	    tail = temp->prev;  
	}
    res = temp->data;
    free(temp);
    return res;
}

//Function to search for an element in a doubly linked list
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

//Function to display all the elements of the doubly linked list
void List::display()
{
	printf("Doubly Linked List in forward direction:\n");
    struct node *temp=head;
    while(temp)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\nDoubly Linked List in backward direction:\n");
    temp = tail;
    while(temp)
    {
        printf("%d  ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
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
