//Lab 11 Q c
# include <cstdio>
# include <cstdlib>
# define SIZE 10

class Hashtable{
    struct node{
        int data;
        node* next;
    };
    node* table[SIZE];
    int hashFunction(int key) {
        return key % SIZE;
    }
    public:

        Hashtable(){
           for(int i=0;i<SIZE;i++){
            table[i]=nullptr;
           }
        }
        void insert(int key);
        int deleteKey(int key);
        int search(int key);
        void display();
};

//Main Function
int main() {
    Hashtable ht;
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
        case 3:{
             printf("Enter the key you want to search:");
             scanf("%d",&key);
             int x;
             x=ht.search(key);
             int index = x/ 100;
             int pos = x % 100;
             if(x!=-1){
                printf("Element found at table[%d], position %d in chain.\n", index, pos);
             }
            else{
                   printf("Not found");
            }
            break;}
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
void Hashtable :: insert(int key){
    int index=hashFunction(key);
    node* newnode=new node;
    newnode->data=key;
    newnode->next=table[index];
    table[index]=newnode;
}

//Function to delete a key
int Hashtable :: deleteKey(int key){
    int index=hashFunction(key);
    node* current=table[index];
    node* prev=nullptr;

    while(current!=nullptr){
        if(current->data==key){
            int deleted=current->data;
        
        if(prev==nullptr){
            table[index]=current->next;
        }else{
            prev->next=current->next;
        }

        delete current;
        return deleted ;
        } 
        prev=current;
        current=current->next; 
    }
    return -1;
}

//Function to search for a key
int Hashtable :: search(int key){
    int index=hashFunction(key);
    node* current=table[index];
    int pos=0;
    while(current!=nullptr){
        if(current->data==key){
            return index*100+pos;
        }
        current=current->next;
        pos++;
    }
    return -1;
}

//Function to display the Hash table
void Hashtable :: display(){
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        node* current = table[i];
        if (!current) {
            printf("EMPTY\n");
            continue;
        }
        while (current != nullptr) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}