#include<stdio.h>
int calc(int num)
{
    int arr[num];
    int c=0;
    int arr1[num];
    int temp=0;
    for(int i=0;i<num;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<temp;j++)
        {
            if(arr1[j]==arr[i])
            {
                c=j+1;
            }
        }
        arr1[temp]=arr[i];
        temp++;
    }
    return c;
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test)
    {
        int num;
        scanf("%d",&num);
        printf("%d",calc(num));
        test--;
    }
    return 0;
}