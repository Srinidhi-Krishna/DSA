//Lab 9 Question 3

#include <stdio.h>
#include <stdlib.h>

class BST {
private:
    struct Node {
        int data;
        Node *left, *right;
        Node(int val) { data = val; left = right = NULL; }
    };

    Node* root;  

    // Private recursive functions
    Node* insert(Node* node, int val);  
    void inorder(Node* node);
    void preorder(Node* node);
    void postorder(Node* node);
    bool search(Node* node, int val);

public:
    BST() { root = NULL; }  

    // Public functions (User-friendly interface)
    void insert(int val); 
    void inorder(); 
    void preorder(); 
    void postorder(); 
    bool search(int val); 
};


// Public wrapper for insert
void BST::insert(int val) { 
    root = insert(root, val); 
}

// Public wrapper for inorder
void BST::inorder() { 
    inorder(root); 
    printf("\n"); 
}

// Public wrapper for preorder
void BST::preorder() { 
    preorder(root); 
    printf("\n"); 
}

// Public wrapper for postorder
void BST::postorder() { 
    postorder(root); 
    printf("\n"); 
}

// Public wrapper for search
bool BST::search(int val) { 
    return search(root, val); 
}

BST::Node* BST :: insert(Node* node, int val) {
    if (!node) return new Node(val);
    if(node->data > val)
        node->left = insert(node->left, val);
    else
        node->right = insert(node->right, val);

    return node;
}

void BST::inorder(Node* node) {
    if (!node) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void BST::preorder(Node* node) {
    if (!node) return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void BST::postorder(Node* node) {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

bool BST::search(Node* node, int val) {
    if (!node) return false;
    if (node->data == val) return true;
    return val < node->data ? search(node->left, val) : search(node->right, val);
}

//Main Function

int main() {
    BST tree;
    int choice, val;

    while (true) {
        printf("\nMenu:\n");
        printf("1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Search\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                tree.insert(val);
                break;
            case 2:
                printf("Inorder: ");
                tree.inorder();
                break;
            case 3:
                printf("Preorder: ");
                tree.preorder();
                break;
            case 4:
                printf("Postorder: ");
                tree.postorder();
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &val);
                printf(tree.search(val) ? "Value found!\n" : "Value not found.\n");
                break;
            case 6:
            	printf("Exiting!\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
}
