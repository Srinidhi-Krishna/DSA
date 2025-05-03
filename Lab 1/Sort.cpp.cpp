#include<stdio.h>
void bubble_sort(int arr[],int size);
void selection_sort(int arr[],int size);
void insertion_sort(int arr[],int size);
void display_array(int arr[],int size);

int main()
{
    int size,choice;
    printf("Enter the number of elements in the array:");
    scanf("%d",&size);
    int arr[size];
    for (int i=0;i<size;i++)
    {
        int element;
        printf("Enter the element:");
        scanf("%d",&element);
        arr[i]=element;
    }
    printf("Menu:\n1:Bubble Sort\n2:Selection Sort\n3:Insertion Sort\n4:Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    while(choice!=4)
    {
        switch (choice)
        {
            case 1:
                bubble_sort(arr,size);
                display_array(arr,size);
                break;
            case 2:
                selection_sort(arr,size);
                display_array(arr,size);
                break;
            case 3:
                insertion_sort(arr,size);
                display_array(arr,size);
                break;

        }
        printf("Menu:\n1:Bubble Sort\n2:Selection Sort\n3:Insertion Sort\n4:Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
    }
}

//Function for bubble sort
void bubble_sort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

//Function for selection sort
void selection_sort(int arr[],int size)
{   
    for(int i=0;i<size-1;i++)
    { 
        int minindex;
        int flag=0;
        minindex=i;
        for(int j=i+1;j<size;j++)
        {  
            if(arr[j]<arr[minindex])
            {
                minindex=j;
                flag=1;
            }
            
        }
        if(flag==1)
        {   
            int temp;
            temp=arr[i];
            arr[i]=arr[minindex];
            arr[minindex]=temp;
        }
        
    }
}

//Function for insertion sort
void insertion_sort(int arr[],int size)
{
    for (int i=1;i<size;++i)
    {
        int j=i-1;
        int key=arr[i];
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

//Function for displaying the array
void display_array(int arr[],int size)
{
    printf("Sorted array in ascending order:\n");
    for(int i=0;i<size;i++)
    {
        printf("%d\n",arr[i]);
    }
}