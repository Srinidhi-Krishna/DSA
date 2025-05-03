//Nene's Game

#include<stdio.h>

class player
{
    private:
        int min_val;
    public:
        player()
        {
            min_val=-1;
        }
        int min(int arr_pos[], int pos);
        int game(int grp, int min);
};

//Main Function
int main()
{
    int test;
    scanf("%d",&test);
    while(test)
    {
        player p;
        int num_pos,num_grp;
        scanf("%d",&num_pos);
        scanf("%d",&num_grp);
        int arr_pos[num_pos];

        // Constructing the array containing the positions of the players that are to be deleted

        for(int i=0;i<num_pos;i++)
        {
            scanf("%d",&arr_pos[i]);
        }

        int min_val;
        min_val=p.min(arr_pos,num_pos);
        int arr[num_grp];

        // Constructing the array containing the number of the players 

        for(int i=0;i<num_grp;i++)
        {
            scanf("%d",&arr[i]);
        }

        // Displaying the generated output

        for (int i=0;i<num_grp;i++)
        {
            printf("%d ",p.game(arr[i],min_val));
        }
        printf("\n");
        test--;
    }
    return 0;
}

// Function to find the minimum value in the position array

int player::min(int arr_pos[],int pos)
{
    int min_val=arr_pos[0];
    for(int i=0;i<pos;i++)
    {
        if(arr_pos[i]<min_val)
        {
            min_val=arr_pos[i];
        }
    }
    return min_val;
}

// Function to return the number of winners

int player::game(int grp,int min)
{
    if (grp>=min)
    {
        return min-1;
    }
    return grp;
}
