// Lab 9 Question 2

#include<stdio.h>

class maximum
{
    private:
        int max;
        int sec_max;
    public:
        maximum()
        {
            max=-1;
            sec_max=-1;
        }
        void max_secmax(int arr[], int num);
        void display(int arr[], int num);
};

//Main Function

int main()
{
    int test;
    scanf("%d",&test);
    while(test)
    {
        maximum m;
        int num;
        scanf("%d",&num);
        int arr[num];
        for (int i=0;i<num;i++)
        {
            scanf("%d",&arr[i]);
        }
        m.max_secmax(arr,num);
        m.display(arr,num);
        test--;
    }
    return 0;
}

//Function to find the maximum and second maximum value

void maximum::max_secmax(int arr[], int num)
{
    for(int i=0;i<num;i++)
    {
        if(arr[i]>max)
        {
            sec_max=max;
            max=arr[i];
        }
        else if (arr[i]>sec_max and max!=arr[i])
        {
            sec_max=arr[i];
        }
    }
    if (sec_max==-1)
    {
        sec_max=max;
    }
}

// Function to display the desired output

void maximum::display(int arr[], int num)
{
    for(int i=0;i<num;i++)
    {
        if(arr[i]!=max)
        {
            printf("%d ",arr[i]-max);
        }
        else
        {
            printf("%d ",arr[i]-sec_max);
        }
    }
    printf("\n");
}