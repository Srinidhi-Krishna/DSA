//Tower Question - Finding the maximum number of blocks

#include<stdio.h>

//Function to find the maximum number of towers

int tower()
{
	int t;
	scanf("%d",&t);
	int arr[t];
	for(int i = 0;i < t;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	int beg=arr[0];
	
	//Performing bubble sort on the array
	
	for(int i = 0;i < t-1;i++)
	{
		for(int j = 0;j < t-1-i;j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	for (int i = 1;i < t;i++)
	{
		if (arr[i] > beg)
		{
			int excess = arr[i]-beg;
			beg += (excess+1)/2;
		}
	}
	return beg;
}

//Main Function

int main()
{
	printf("Input:\n");
	int size;
	scanf("%d",&size);
	int arr[size];
	for(int i = 0;i < size;i++) 
	{
		arr[i] = tower();
	}
	
	//Displaying the output
	
	printf("Output:\n");
	for(int i = 0;i < size;i++) 
	{
		printf("%d\n",arr[i]);	
	}
	return 0;
}
