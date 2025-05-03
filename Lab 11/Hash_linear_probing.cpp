//Lab 11 Q a
#include <stdio.h>
#define SIZE 10
#define EMPTY -1
#define DELETED -2

class HashTable{
    int arr[SIZE];
    public:
        HashTable(){
            for(int i=0;i<SIZE;i++){
                arr[i]=-1;
            }
        }
        int hashfunction(int key){
          return key % SIZE;
       } 
       void insert(int); 
       void display(); 
       int Delete(int);
       int Search(int);
};

//Main Function
int main(){
    HashTable h;
    int choice;
    int key;
    do{
        printf("Menu\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Search\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the key you want to insert:");
                scanf("%d",&key);
                h.insert(key);
                break;

            case 2:
                printf("Enter the key you want to delete:");
                scanf("%d",&key); 
                h.Delete(key);
                break;

            case 3:
                printf("Enter the key you want to search:");
                scanf("%d",&key);
                int x;
                x=h.Search(key);
                if(x!=-1){
                    printf("Element found at %d\n",x);
                }
                else{
                    printf("Not found");
                }
                break;

            case 4:
                 h.display();
                 break;
            case 5:
                printf("Exiting...\n");
                break;                
        }
    }while(choice!=5);
    return 0;
}

//Function to insert a new key
void HashTable :: insert(int key){
    int index=hashfunction(key);
    int mainindex=index;

    while(arr[index]!=EMPTY){
        index=(index+1)% SIZE;
        if(index==mainindex){
            printf("Hash is full.");
        }
    }
    arr[index]=key;
    return;
}

//Function to display the Hash table
void HashTable :: display(){
    for(int i= 0;i<SIZE;i++){
        if(arr[i]==EMPTY){
            printf("%d: %s",i,"EMPTY\n");
        }
        else if(arr[i]==DELETED){
            printf("%d: %s",i,"DELETED\n");
        }
        else{
            printf("%d: %d\n",i,arr[i]);
        }
    }
}

//Function to delete a key
int HashTable :: Delete(int key){
    int index=hashfunction(key);
    int mainindex=index;
    int temp;
    while(arr[index]!=EMPTY){
       if(arr[index]==key){
         temp=index;
         arr[index]=DELETED;
         return temp; 
       }  
       index=(index+1)%SIZE;
       if(index==mainindex){
           break;
        }
    }
    return -1;
     
}

//Function to search for a key
int HashTable :: Search(int key){
    int index=hashfunction(key);
    int mainindex=index;

    while(arr[index]!=EMPTY){
       if(arr[index]==key){
         return arr[index];
       }  
       index=(index+1)%SIZE;
       if(index==mainindex){
           break;
        }
    } 
    return -1;   

}