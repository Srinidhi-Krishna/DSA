#include "list.h"

// Constructor
LinkedList::LinkedList()
{
    head = NULL;
}

// Private function to get head
Node *LinkedList::gethead()
{
    return head;
}

// Function to insert in ascending order
void LinkedList::insertAscending(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || head->data >= value)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL && temp->next->data < value)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

//Function to merge the two lists in ascending order
LinkedList LinkedList::mergeLists(LinkedList &list2) {
    LinkedList mergedList; 
    Node* current1 = head; 
    Node* current2 = list2.head;

    while (current1 || current2) {
        if (!current2 || (current1 && current1->data <= current2->data)) {
            mergedList.insertAscending(current1 ? current1->data : current2->data);
            if (current1) current1 = current1->next;
        } else {
            mergedList.insertAscending(current2->data);
            current2 = current2->next;
        }
    }
    return mergedList; 
}
//Function to display the list
void LinkedList::display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

// Main function with menu-driven program
int main()
{
    LinkedList list1, list2, mergedList;
    int choice, value;
	printf("Menu:\n1. Insert into List1\n2. Insert into List2\n3. Merge into List3\n4. Display Lists\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
	while (choice!=5)
    {
        switch (choice)
        {
        case 1:
            printf("Enter value to insert in List1: ");
            scanf("%d", &value);
            list1.insertAscending(value);
            break;
            
        case 2:
            printf("Enter value to insert in List2: ");
            scanf("%d", &value);
            list2.insertAscending(value);
            break;
            
        case 3:
            mergedList = list1.mergeLists(list2);
            printf("Merged List3 in Ascending Order.\n");
            break;
            
        case 4:
            printf("List1: ");
            list1.display();
            printf("\nList2: ");
            list2.display();
            printf("\nMerged List3: ");
            mergedList.display();
            break;

        default:
            printf("Invalid choice!\n");
        }
        printf("\nMenu:\n1. Insert into List1\n2. Insert into List2\n3. Merge into List3\n4. Display Lists\n5. Exit\n");
    	printf("Enter your choice: ");
    	scanf("%d", &choice);
    }
    printf("Exiting!\n");
    return 0;
}
