//Lab 9 Question 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"  

// Node structure
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
    Node(char val) { data = val; left = right = NULL; }
};

// ExpressionTree class
class ExpressionTree {
private:
    struct Node* root;
    
    // Function to check if a character is an operator
    bool isOperator(char c);
    
    // Recursive function for preorder traversal
    void preorder(struct Node* node);
    
    // Recursive function for inorder traversal
    void inorder(struct Node* node);
    
    // Recursive function for postorder traversal
    void postorder(struct Node* node);

public:
    ExpressionTree() { root = NULL; }
    
    // Function to construct an expression tree from postfix expression
    void constructFromPostfix(const char* postfix);
    
    // Function to print preorder traversal
    void printPreorder();
    
    // Function to print inorder traversal
    void printInorder();
    
    // Function to print postorder traversal
    void printPostorder();
};

// Main Function 
int main() {
    char postfix[100];
    ExpressionTree tree;
    int choice;
    
    do {
        printf("\n1. Enter Postfix Expression");
        printf("\n2. Construct Expression Tree");
        printf("\n3. Preorder");
        printf("\n4. Inorder");
        printf("\n5. Postorder");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter postfix expression: ");
                scanf("%s", postfix);
                break;
            case 2:
                tree.constructFromPostfix(postfix);
                printf("Expression tree constructed.\n");
                break;
            case 3:
                tree.printPreorder();
                break;
            case 4:
                tree.printInorder();
                break;
            case 5:
                tree.printPostorder();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 6);
    
    return 0;
}

// Function to check if a character is an operator
bool ExpressionTree::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to construct an expression tree from postfix expression
void ExpressionTree::constructFromPostfix(const char* postfix) {
    struct Node* stack[100];
    int top = -1;
    
    for (int i = 0; i < strlen(postfix); i++) {
        char c = postfix[i];
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = c;
        newNode->left = newNode->right = NULL;
        
        if (isOperator(c)) {
            if (top < 1) {
                printf("Invalid postfix expression!\n");
                return;
            }
            newNode->right = stack[top--];
            newNode->left = stack[top--];
        }
        stack[++top] = newNode;
    }
    
    if (top != 0) {
        printf("Invalid postfix expression!\n");
        return;
    }
    root = stack[top];
}

// Recursive function for preorder traversal
void ExpressionTree::preorder(struct Node* node) {
    if (node) {
        printf("%c ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

// Recursive function for inorder traversal
void ExpressionTree::inorder(struct Node* node) {
    if (node) {
        inorder(node->left);
        printf("%c ", node->data);
        inorder(node->right);
    }
}

// Recursive function for postorder traversal
void ExpressionTree::postorder(struct Node* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        printf("%c ", node->data);
    }
}

// Function to print preorder traversal
void ExpressionTree::printPreorder() {
    printf("Preorder: ");
    preorder(root);
    printf("\n");
}

// Function to print inorder traversal
void ExpressionTree::printInorder() {
    printf("Inorder: ");
    inorder(root);
    printf("\n");
}

// Function to print postorder traversal
void ExpressionTree::printPostorder() {
    printf("Postorder: ");
    postorder(root);
    printf("\n");
}

