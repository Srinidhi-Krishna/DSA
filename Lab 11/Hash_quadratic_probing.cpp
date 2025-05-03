//Lab 11 Q b
#include <cstdio>

#define SIZE 5
#define EMPTY -1
#define DELETED -2
#define C1 1
#define C2 1

class HashTable {
    int hashTable[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            hashTable[i] = EMPTY;
        }
    }

    int hashFunction(int key) {
        return key % SIZE;
    }

    void insert(int key);
    int deleteKey(int key);
    int search(int key);
    void display();
};

//Main Function
int main() {
    HashTable ht;
    int choice, key;
    do {
        printf("\nMenu:\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            ht.insert(key);
            break;
        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            ht.deleteKey(key);
            break;
        case 3:
             printf("Enter the key you want to search:");
             scanf("%d",&key);
             int x;
             x=ht.search(key);
             if(x!=-1){
                 printf("Element found at %d\n",x);
             }
            else{
                   printf("Not found");
            }
            break;
        case 4:
            ht.display();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}

//Function to insert a new key
void HashTable :: insert(int key){
    int h=hashFunction(key);
    int i=0;

    while(i<SIZE){
        int prindex = (h + C1 * i + C2 * i * i) % SIZE;
        if(hashTable[prindex]==EMPTY){
            hashTable[prindex]=key;
            return;
        }
        i++;
    }

    printf("Hash is full.");
}

//Function to delete a key
int HashTable :: deleteKey(int key){
    int h=hashFunction(key);
    int i=0;
    int temp;
    while(i<SIZE){
        int prindex = (h + C1 * i + C2 * i * i) % SIZE;
        if(hashTable[prindex]==key){
            temp=hashTable[prindex];
            hashTable[prindex]=DELETED;
            return temp;
        }
        i++;
    }
    return -1;
}

//Function to search for a key
int HashTable :: search(int key){
    int h=hashFunction(key);
    int i=0;
    int temp;
    while(i<SIZE){
        int prindex = (h + C1 * i + C2 * i * i) % SIZE;
        if(hashTable[prindex]==key){
            temp=prindex;
            return temp;
        }
        i++;
    }
    return -1;

}

//Function to display the Hash table
void HashTable :: display(){
    for(int i= 0;i<SIZE;i++){
        if(hashTable[i]==EMPTY){
            printf("%d: %s",i,"EMPTY\n");
        }
        else if(hashTable[i]==DELETED){
            printf("%d: %s",i,"DELETED\n");
        }
        else{
            printf("%d: %d\n",i,hashTable[i]);
        }
    }
}