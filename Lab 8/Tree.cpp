//Using Tree ADT perform - Insertion, Preorder Traversal, Inorder Traversal, Postorder Traversal, Search & Exit
#include <stdio.h>
#include <stdlib.h>

class Tree {
    struct Node {
        char data;
        struct Node *left, *right;
    } *root;

public:
    Tree() {
        root = NULL;
    }
    int insert(char);
    void preorder(Node*);
    void inorder(Node*);
    void postorder(Node*);
    bool search(char);
    bool searchHelper(Node*, char);
    void display(int);
    Node* getRoot() { return root; }
};

//Menu Driven Main Function

int main() {
    Tree t;
    int ch, result;
    char val;
    printf("Menu:\n1:Insert\n2:Preorder\n3:Inorder\n4:Postorder\n5:Search\n6:Exit\n");
    printf("Enter your choice:");
    scanf("%d", &ch);
    
    while (ch != 6) {
        switch (ch) {
            case 1:
            	//Insertion
                printf("Enter character to insert: ");
                scanf(" %c", &val);
                result = t.insert(val);
                if (result == 0) {
                    printf("Memory allocation failed or Parent not found!\n");
                }
				else if(result == -1){
					printf("Left child already exists!\n");
				}
				else if(result == -2)
				{
					printf("Right child already exists!\n");
				}
				else if(result == -3)
				{
					printf("Invalid direction!\n");
				}
				else if(result == -4)
				{
					printf("Parent node not found!\n");
				}
   	     		else {
                    printf("Operation Successful!\n");
                }
                break;
                
            case 2:
            	//Preorder Traversal
                printf("Preorder Traversal: ");
                t.display(2);
                break;
                
            case 3:
            	//Inorder Traversal
                printf("Inorder Traversal: ");
                t.display(3);
                break;
                
            case 4:
            	//Postorder Traversal
                printf("Postorder Traversal: ");
                t.display(4);
                break;
                
            case 5:
            	//Search
                printf("Enter character to search: ");
                scanf(" %c", &val);
                result = t.search(val);
                if (result == 1) {
                    printf("Element Found!\n");
                } else {
                    printf("Element Not Found!\n");
                }
                break;
                
            default:
            	//Invalid Choice
                printf("Invalid Choice! Try again!\n");
                break;
        }
        printf("\nMenu:\n1:Insert\n2:Preorder\n3:Inorder\n4:Postorder\n5:Search\n6:Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
    }
    printf("Exiting!\n");
    return 0;
}

//Function to insert a character into the tree
int Tree::insert(char val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return 0;
    }
    newNode->data = val;
    newNode->left = newNode->right = NULL;

    if (root == NULL) {
        root = newNode;
        return 1;
    }
    
    char parentVal, direction;
    printf("Enter parent node value: ");
    scanf(" %c", &parentVal);
    
    Node* temp = root;
    while (temp != NULL) {
        if (temp->data == parentVal) {
            printf("Enter L to insert as left child or R to insert as right child: ");
            scanf(" %c", &direction);
            if (direction == 'L' || direction == 'l') {
                if (temp->left == NULL) {
                    temp->left = newNode;
                    return 1;
                } else {
                    free(newNode);
                    return -1;
                }
            } else if (direction == 'R' || direction == 'r') {
                if (temp->right == NULL) {
                    temp->right = newNode;
                    return 1;
                } else {
                    free(newNode);
                    return -2;
                }
            } else {
                free(newNode);
                return -3;
            }
        }
        temp = temp->left;
        if (temp == NULL) temp = temp->right;
    }
    free(newNode);
    return -4;
}

//Preorder traversal of the tree
void Tree::preorder(Node* node) {
    if (node != NULL) {
        printf("%c ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

//Inorder traversal of the tree
void Tree::inorder(Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%c ", node->data);
        inorder(node->right);
    }
}

//Postorder traversal of the tree
void Tree::postorder(Node* node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%c ", node->data);
    }
}

//Searching for a character in the tree
bool Tree::search(char val) {
    return searchHelper(root, val);
}

bool Tree::searchHelper(Node* node, char val) {
    if (node == NULL) {
        return false;
    }
    if (node->data == val) {
        return true;
    }
    return searchHelper(node->left, val) || searchHelper(node->right, val);
}

//To display the traversal
void Tree::display(int option) {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return;
    }
    switch (option) {
        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
    }
    printf("\n");
}

