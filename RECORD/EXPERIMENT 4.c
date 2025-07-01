#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct Node* insertAfterPosition(struct Node* head, int data, int position) {
    int i;
if (head == NULL || position < 1) {
        printf("Position out of range\n");
        return head;
    }
    struct Node* temp = head;
    for (i = 1; i < position && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of range\n");
        return head;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
    return head;
}

struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;
    free(temp);
    return head;
}

struct Node* deleteAtPosition(struct Node* head, int position) {
   int i;
if (head == NULL || position < 1) {
        printf("Position out of range\n");
        return head;
    }
    struct Node* temp = head;
    for (i = 1; i < position && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of range\n");
        return head;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    return head;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position after which to insert: ");
                scanf("%d", &position);
                head = insertAfterPosition(head, data, position);
                break;
            case 4:
                head = deleteAtBeginning(head);
                break;
            case 5:
                head = deleteAtEnd(head);
                break;
            case 6:
                printf("Enter position of node to delete: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 7:
                printf("Doubly Linked List: ");
                displayList(head);
                break;
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

createNode

Step 1: Start.

Step 2: Allocate memory for a new node using malloc.

Step 3: Set the data of the node to the provided value, and both prev and next to NULL.

Step 4: Return the newly created node.

Step 5: Stop.


---

insertAtBeginning

Step 1: Start.

Step 2: Create a new node by calling createNode(data).

Step 3: Set the new node's next to the current head of the list.

Step 4: If the list is not empty, set the prev pointer of the current head to the new node.

Step 5: Return the new node as the new head of the list.

Step 6: Stop.


---

insertAtEnd

Step 1: Start.

Step 2: Create a new node by calling createNode(data).

Step 3: If the list is empty (head is NULL), return the new node as the head.

Step 4: Otherwise, traverse to the last node by checking next != NULL.

Step 5: Set the next pointer of the last node to the new node and set the prev pointer of the new node to the last node.

Step 6: Return the head of the list.

Step 7: Stop.


---

insertAfterPosition

Step 1: Start.

Step 2: If the head is NULL or the position is less than 1, print "Position out of range" and return the list unchanged.

Step 3: Traverse the list to the specified position by checking temp != NULL and incrementing i until reaching the desired position.

Step 4: If the position is out of range, print "Position out of range" and return the list unchanged.

Step 5: Create a new node by calling createNode(data).

Step 6: Set the new node’s next to the next of the current node, and update the prev of the next node (if it exists) to the new node.

Step 7: Set the next of the current node to the new node and the prev of the new node to the current node.

Step 8: Return the head of the list.

Step 9: Stop.


---

deleteAtBeginning

Step 1: Start.

Step 2: If the list is empty (head is NULL), print "List is empty" and return the list unchanged.

Step 3: Set the head to the next node of the current head.

Step 4: If the new head is not NULL, set its prev to NULL.

Step 5: Free the old head node.

Step 6: Return the updated head of the list.

Step 7: Stop.


---

deleteAtEnd

Step 1: Start.

Step 2: If the list is empty (head is NULL), print "List is empty" and return the list unchanged.

Step 3: Traverse to the last node by checking next != NULL.

Step 4: Set the next pointer of the previous node to NULL (if the last node is not the head).

Step 5: If the last node is the head (only one node), set the head to NULL.

Step 6: Free the last node.

Step 7: Return the updated head of the list.

Step 8: Stop.


---

deleteAtPosition

Step 1: Start.

Step 2: If the head is NULL or the position is less than 1, print "Position out of range" and return the list unchanged.

Step 3: Traverse the list to the specified position by checking temp != NULL and incrementing i until reaching the desired position.

Step 4: If the position is out of range, print "Position out of range" and return the list unchanged.

Step 5: If the node to be deleted is not the first node, update the next pointer of the previous node to skip the node to be deleted.

Step 6: If the node to be deleted is not the last node, update the prev pointer of the next node to skip the node to be deleted.

Step 7: Free the node to be deleted.

Step 8: Return the updated head of the list.

Step 9: Stop.


---

displayList

Step 1: Start.

Step 2: If the list is empty (head is NULL), print nothing.

Step 3: Traverse the list starting from head, printing the data of each node.

Step 4: Print a newline after displaying all elements.

Step 5: Stop.


---

main

Step 1: Start.

Step 2: Display the menu with the following options:

1. Insert at beginning



2. Insert at end



3. Insert after position



4. Delete at beginning



5. Delete at end



6. Delete at position



7. Display list



8. Exit




Step 3: Read the user's choice.

Step 4: If the choice is:

1 (Insert at beginning): Read data and call insertAtBeginning(head, data).

2 (Insert at end): Read data and call insertAtEnd(head, data).

3 (Insert after position): Read data and position, then call insertAfterPosition(head, data, position).

4 (Delete at beginning): Call deleteAtBeginning(head).

5 (Delete at end): Call deleteAtEnd(head).

6 (Delete at position): Read position, then call deleteAtPosition(head, position).

7 (Display list): Call displayList(head).

8 (Exit): Exit the program.

Default: Print "Invalid choice! Please try again".


Step 5: Repeat the menu until the user chooses option 8 (Exit).

Step 6: Stop.
