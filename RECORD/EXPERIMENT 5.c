#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Inorder Traversal\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

createNode

Step 1: Start.

Step 2: Allocate memory for a new node using malloc.

Step 3: Set the data of the new node to the given data, and set both left and right pointers to NULL.

Step 4: Return the newly created node.

Step 5: Stop.


---

insert

Step 1: Start.

Step 2: If the root is NULL, create a new node with the given data and return it as the root.

Step 3: If data is less than the root's data, recursively call insert on the left subtree.

Step 4: If data is greater than the root's data, recursively call insert on the right subtree.

Step 5: Return the root (after insertions).

Step 6: Stop.


---

findMin

Step 1: Start.

Step 2: Start with the given node as current.

Step 3: Traverse the left child of the current node until current->left is NULL.

Step 4: Return the node which is the leftmost (minimum) node.

Step 5: Stop.


---

deleteNode

Step 1: Start.

Step 2: If the root is NULL, return NULL (node not found).

Step 3: If data is less than the root's data, recursively call deleteNode on the left subtree.

Step 4: If data is greater than the root's data, recursively call deleteNode on the right subtree.

Step 5: If data is equal to the root's data (node to delete):

If the node has no left child, replace it with its right child.

If the node has no right child, replace it with its left child.

If the node has both children, find the minimum value node in the right subtree, replace the node’s data with the minimum value, and delete the minimum value node from the right subtree.


Step 6: Return the root.

Step 7: Stop.


---

inorder

Step 1: Start.

Step 2: If the root is NULL, return.

Step 3: Recursively traverse the left subtree.

Step 4: Print the data of the current node.

Step 5: Recursively traverse the right subtree.

Step 6: Stop.


---

main

Step 1: Start.

Step 2: Display the menu with options:

1. Insert

2. Delete

3. Inorder Traversal

4. Exit


Step 3: Read the user's choice.

Step 4: If the choice is:

1 (Insert): Read the value and call insert(root, value).

2 (Delete): Read the value and call deleteNode(root, value).

3 (Inorder Traversal): Call inorder(root) to display the tree in inorder.

4 (Exit): Exit the program.

Default: Print "Invalid choice! Please try again."


Step 5: Repeat the menu until the user chooses option 4.

Step 6: Stop.
