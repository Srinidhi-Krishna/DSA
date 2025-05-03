#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void palindrome();
void armstrong_number();
void perfect_number();
int reverse(int *num);

int main()
{
    int *ch;
    ch=(int*)malloc(sizeof(int));
    printf("Menu:\n1:Palindrome\n2:Armstrong Number\n3:Perfect Number\n4:Exit");
    printf("\nEnter your choice:");
    scanf("%d",ch);
    while(*ch!=4)
    {
        switch (*ch)
        {
        case 1:
            palindrome();
            break;
        case 2:
            armstrong_number();
            break;
        case 3:
            perfect_number();
            break;
        }
    printf("\nMenu:\n1:Palindrome\n2:Armstrong Number\n3:Perfect Number\n4:Exit");
    printf("\nEnter your choice:");
    scanf("%d",ch);
    }
    free(ch);
}

//To check if the number is palindrome or not
void palindrome()
{   
    int *num;
    num=(int*)malloc(sizeof(int));
    printf("Enter the number:");
    scanf("%d",num);
    int *result;
    result=(int*)malloc(sizeof(int));
    *result=reverse(num);
    if(*result==*num)
    {
        printf("%d:The number is Palindrome",*num);
    }
    else
    {
        printf("%d:The number is not Palindrome",*num);
    }
    free(num);
    free(result);
}

//To check if the number is an armstrong number or not
void armstrong_number()
{
    int *num;
    num=(int*)malloc(sizeof(int));
    printf("Enter the number:");
    scanf("%d",num);
    int *digit;
    digit=(int*)malloc(sizeof(int));
    *digit=0;
    int *temp;
    temp=(int*)malloc(sizeof(int));
    *temp=*num;
    while(*temp>0)
    {
        *digit+=1;
        *temp/=10;
    }
    int *sum;
    int *temp1;
    temp1=(int*)malloc(sizeof(int));
    sum=(int*)malloc(sizeof(int));
    *temp1=*num;
    *sum=0;
    while(*temp1>0)
    {
        int *rim;
        rim=(int*)malloc(sizeof(int));
        *rim=*temp1%10;
        *sum+=pow(*rim,*digit);
        *temp1/=10;
        free(rim);
    }
    printf("Sum:%d\n",*sum);
    free(temp1);
    free(temp);
    free(digit);
    if(*sum==*num)
    {
        printf("%d:It is an Armstrong Number",*num);
    }
    else
    {
        printf("%d:It is not an Armstrong Number",*num);
    }
    free(num);
    free(sum);
}

//To check if the number is a perfect number or not
void perfect_number()
{
    int *num;
    num=(int*)malloc(sizeof(int));
    printf("Enter the number:");
    scanf("%d",num);
    int *i;
    i=(int*)malloc(sizeof(int));
    int *sum;
    sum=(int*)malloc(sizeof(int));
    *sum=0;
    for(*i=1;*i<*num;(*i)++)
    {
        if(*num%*i==0)
        {
            *sum+=*i;
        }
    }
    printf("Sum:%d\n",*sum);
    if(*sum==*num)
    {
        printf("%d:It is a Perfect Number",*num);
    }
    else
    {
        printf("%d:It is not a Perfect Number",*num);
    }
    free(i);
    free(num);
    free(sum);
}

//To return the reversed number
int reverse(int *num)
{
    int *temp;
    temp=(int*)malloc(sizeof(int));
    int *sum;
    sum=(int*)malloc(sizeof(int));
    *sum=0;
    *temp=*num;
    while(*temp>0)
    {
        int *rim;
        rim=(int*)malloc(sizeof(int));
        *rim=*temp%10;
        *sum=((*sum)*10)+(*rim);
        *temp/=10;
        free(rim);
    }
    free(temp);
    return *sum;
    free(sum);
}
