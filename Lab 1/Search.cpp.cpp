#include<stdio.h>
#include"sort.h"
int linear_search(int arr[],int size,int element);
int binary_search(int arr[],int size,int element);

int main()
{
    int choice;
    printf("Menu:\n1:Linear Search\n2:Binary Search\n3:Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    while (choice!=3)
    {
        int size,result;
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
        int element;
        printf("Enter the element to be searched:");
        scanf("%d",&element);
        switch(choice)
        {
            case 1:
                result=linear_search(arr,size,element);
                break;
            case 2:
                bubble_sort(arr,size);
                display_array(arr,size);
                result=binary_search(arr,size,element);
                break;
        }
        if(result!=-1)
        {
            printf("The element is found at the index:%d\n",result);
        }
        else
        {
            printf("The element is not present in the given array\n");
        }
        
        printf("Menu:\n1:Linear Search\n2:Binary Search\n3:Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
    }
}

//Function for linear search
int linear_search(int arr[],int size,int element)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==element)
        {
            return i;
        }
    }
    return -1;
}

//Function for binary search
int binary_search(int arr[],int size,int element)
{
    int start,end;
    start=0;
    end=size-1;
    while(start<=end)
    {
        int mid;
        mid=(start+end)/2;
        if(arr[mid]==element)
        {
            return mid;
        }
        else if(arr[mid]<element)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return -1;
}

