#include<stdio.h>
#define size 5

class list
{
    private:
        int arr[size];
        int curr;
    public:
        list()
        {
            curr=0;
        }
        int checkfull();
        int checkempty();
        int checkpos(int position);
        void insert_begin(int value);
        void insert_end(int value);
        void insert_pos(int value,int position);
        int del_begin();
        int del_end();
        int del_pos(int position);
        int search(int value);
        void display();
        void rotate(int k);
};

int main()
{
    int ch;
    printf("Menu:\n1:Insert Beginning\n2:Insert End\n3:Insert Position\n4:Delete Beginning\n5:Delete End\n6:Delete Position\n7:Search\n8:Display\n9:Rotate\n10:Exit");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    int value,position,result,result1,k;
    list adt;
    while (ch!=10)
    {   
        switch(ch)
        {
            case 1:
                printf("Enter the value to be inserted at the beginning:");
                scanf("%d",&value);
                result=adt.checkfull();
                if (result==1)
                {
                   adt.insert_begin(value);
                }
                else
                {
                    printf("List is Full!\n");
                }
                break;
            case 2:
                printf("Enter the value to be inserted at the end:");
                scanf("%d",&value);
                result=adt.checkfull();
                if (result==1)
                {
                    adt.insert_end(value);
                }
                else
                {
                    printf("List is Full!\n");
                }
                break;
            case 3:
                printf("Enter the value to be inserted at the specified position:");
                scanf("%d",&value);
                printf("Enter the position:");
                scanf("%d",&position);
                result=adt.checkfull();
                result1=adt.checkpos(position);
                if(result==1 && result1==1)
                {
                    adt.insert_pos(value,position);
                }
                else if (result==0)
                {
                    printf("List is Full!\n");
                }
                else
                {
                    printf("Invalid Position!\n");
                }
                break;
            case 4:
                result=adt.checkempty();
                if(result==1)
                {
                    result=adt.del_begin();
                    printf("The element deleted from the beginning is:%d\n",result);
                }
                else
                {
                    printf("The List is Empty!\n");
                }
                break;
            case 5:
                result=adt.checkempty();
                if(result==1)
                {
                    result=adt.del_end();
                    printf("The element deleted from the end is:%d\n",result);
                }
                else
                {
                    printf("The List is Empty!\n");
                }
                break;
            case 6:
                printf("Enter the position where the element is to be deleted:");
                scanf("%d",&position);
                result=adt.checkempty();
                result1=adt.checkpos(position);
                if (result==1 && result1==1)
                {
                    result=adt.del_pos(position);
                    printf("The element deleted from the position %d is:%d\n",position,result);
                }
                else if (result==0)
                {
                    printf("List is Empty!\n");
                }
                else
                {
                    printf("Invalid Position!\n");
                }
                break;
            case 7:
                printf("Enter the element to be searched:");
                scanf("%d",&value);
                result=adt.checkempty();
                if(result==1)
                {
                    result1=adt.search(value);
                    if (result1!=-1)
                    {
                        printf("The element %d is present at the index:%d\n",value,result1);
                    }
                    else
                    {
                        printf("The element %d is NOT present in the given list\n",value);
                    }
                } 
                else
                {
                    printf("List is Empty!\n");
                }           
                break;
            case 8:
                adt.display();
                break;
            case 9:
                printf("Enter the number of times the list msut be rotated right:");
                scanf("%d",&k);
                result=adt.checkempty();
                if (result==1)
                {
                    adt.rotate(k);
                }
                else
                {
                    printf("List is Empty!\n");
                }
                break;
        }
        printf("\nMenu:\n1:Insert Beginning\n2:Insert End\n3:Insert Position\n4:Delete Beginning\n5:Delete End\n6:Delete Position\n7:Search\n8:Display\n9:Rotate\n10:Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
    }
}

//Function to check if the list is full
int list::checkfull()
{
    if(curr>=size)
    {
        return 0;
    }
    return 1;
}

//Function to check if the list is empty
int list::checkempty()
{
    if(curr==0)
    {
        return 0;
    }
    return 1;
}

//Function to check if the position is valid
int list::checkpos(int position)
{
    if(position>curr||position<0)
    {
        return 0;
    }
    return 1;
}

//Function to insert an element at the beginning of the list
void list::insert_begin(int value)
{
    for(int i=curr;i>0;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=value;
    curr++;
    return;
}

//Function to insert an element at the end of the list
void list::insert_end(int value)
{    
    arr[curr]=value;
    curr++;
    return;
}

//Function to insert an element at the specified position in the list
void list::insert_pos(int value,int position)
{
    for(int i=curr;i>position;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[position]=value;
    curr++;
    return;
}

//Function to delete an element from the beginning of the list
int list::del_begin()
{
    int result;
    result=arr[0];
    for(int i=0;i<curr-1;i++)
    {
        arr[i]=arr[i+1];
    }
    curr--;
    return result;
}

//Function to delete an element from the end of the list
int list::del_end()
{
    int result;
    result=arr[curr-1];
    curr--;
    return result;
}

//Function to delete an element in the specified position from the list
int list::del_pos(int position)
{
    int result;
    result=arr[position];
    for(int i=position;i<curr;i++)
    {
        arr[i]=arr[i+1];
    }
    curr--;
    return result;
}

//Function to search if the given element is present in the list
int list::search(int value)
{
    
    for(int i=0;i<curr;i++)
    {
        if(arr[i]==value)
        {
            return i;
        }
    }
    return -1;
}

//Function to display the entire list
void list::display()
{
    if(curr==0)
    {
        printf("List is Empty!\n");
        return;
    }
    printf("The elements in the array:\n");
    for(int i=0;i<curr;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");
    return;
}

//To rotate the list right 'k' times 
void list::rotate(int k)
{
    for(int j=0;j<k;j++)
    {
        int element;
        element=arr[curr-1];
        for(int i=curr-1;i>0;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[0]=element;
    }
}