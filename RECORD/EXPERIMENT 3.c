#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    if ((rear + 1) % MAX == front) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full! Cannot insert %d.\n", value);
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        printf("%d inserted into queue.\n", value);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot perform dequeue.\n");
    } else {
        int value = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        printf("%d deleted from queue.\n", value);
    }
}

void display() {
int i;
    if (isEmpty()) {
        printf("Queue is empty! Nothing to display.\n");
    } else {
        printf("Queue elements: ");
         i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

isFull

Step 1: Start.

Step 2: Check if the queue is full:

If (rear + 1) % MAX == front, return 1 (queue is full).

Otherwise, return 0 (queue is not full).


Step 3: Stop.


---

isEmpty

Step 1: Start.

Step 2: Check if the queue is empty:

If front == -1, return 1 (queue is empty).

Otherwise, return 0 (queue is not empty).


Step 3: Stop.


---

enqueue

Step 1: Start.

Step 2: Check if the queue is full by calling isFull().

If full, print "Queue is full! Cannot insert value".

Otherwise:

If front == -1, set front = 0.

Update rear = (rear + 1) % MAX.

Insert the value into queue[rear].

Print "value inserted into queue".



Step 3: Stop.


---

dequeue

Step 1: Start.

Step 2: Check if the queue is empty by calling isEmpty().

If empty, print "Queue is empty! Cannot perform dequeue".

Otherwise:

Retrieve the value to be deleted from queue[front].

If front == rear, set front = rear = -1 (queue is now empty).

Otherwise, update front = (front + 1) % MAX.

Print "value deleted from queue".



Step 3: Stop.


---

display

Step 1: Start.

Step 2: Check if the queue is empty by calling isEmpty().

If empty, print "Queue is empty! Nothing to display".

Otherwise:

Set i = front.

Traverse the queue from front to rear using a while loop, printing each element.

Ensure the loop wraps around the queue using (i + 1) % MAX.

Print the last element queue[rear].



Step 3: Stop.


---

main

Step 1: Start.

Step 2: Display the menu with the following options:

1. Enqueue



2. Dequeue



3. Display



4. Exit




Step 3: Read the user's choice.

Step 4: If the choice is:

1 (Enqueue): Read the value and call enqueue(value).

2 (Dequeue): Call dequeue().

3 (Display): Call display().

4 (Exit): Exit the program.

Default: Print "Invalid choice! Please try again".


Step 5: Repeat the menu until the user chooses option 4 (Exit).

Step 6: Stop.
