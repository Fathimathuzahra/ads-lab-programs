#include <stdio.h>
#include<stdlib.h>
struct stack {
    int data;
    struct stack *next;
};

struct stack *top = NULL;

struct stack *push(struct stack *, int);
struct stack *display(struct stack *);
struct stack *pop(struct stack *);

int main() {
    int val, option;
    do {
        printf("\nMAIN MENU");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. DISPLAY");
        printf("\n 4. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\n Enter the number to be pushed on stack: ");
                scanf("%d", &val);
                top = push(top, val);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                top = display(top);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice");
        }
    } while(option != 4);
    return 0;
}

struct stack *push(struct stack *top, int val) {
    struct stack *ptr;
    ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->data = val;

    if (top == NULL) {
        ptr->next = NULL;
        top = ptr;
    } else {
        ptr->next = top;
        top = ptr;
    }

    return top;
}

struct stack *display(struct stack *top) {
    struct stack *ptr;
    ptr = top;

    if (top == NULL) {
        printf("\n STACK IS EMPTY");
    } else {
        while (ptr != NULL) {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
    }

    return top;
}

struct stack *pop(struct stack *top) {
    struct stack *ptr;
    ptr = top;

    if (top == NULL) {
        printf("\n STACK UNDERFLOW");
    } else {
        top = top->next;
        printf("\n The value being deleted is : %d", ptr->data);
        free(ptr);
    }

    return top;
}

push

Step 1: Start.

Step 2: Allocate memory for a new stack node ptr using malloc.

Step 3: Set ptr->data = val.

Step 4: Check if the stack is empty (top == NULL):

If true, set ptr->next = NULL and top = ptr.

Otherwise, set ptr->next = top and update top = ptr.


Step 5: Return the updated top pointer.

Step 6: Stop.


---

display

Step 1: Start.

Step 2: Set ptr = top.

Step 3: Check if the stack is empty (top == NULL):

If true, print "STACK IS EMPTY".

Otherwise, loop through the stack:

Print ptr->data.

Move ptr to the next node (ptr = ptr->next).



Step 4: Return the top pointer.

Step 5: Stop.


---

pop

Step 1: Start.

Step 2: Set ptr = top.

Step 3: Check if the stack is empty (top == NULL):

If true, print "STACK UNDERFLOW".

Otherwise:

Set top = top->next.

Print the deleted value: ptr->data.

Free the memory allocated for ptr using free(ptr).

Step 4: Return the updated top pointer.

Step 5: Stop.


---

main

Step 1: Start.

Step 2: Display the main menu with options:

1. PUSH

2. POP

3. DISPLAY

4. EXIT

Step 3: Read the user's option.

Step 4: If the option is:

1 (PUSH): Ask for the value, call push(top, val), and update top.

2 (POP): Call pop(top) and update top.

3 (DISPLAY): Call display(top) and update top.

4 (EXIT): Exit the program.

Default: Print "Invalid choice".


Step 5: Repeat until the user chooses option 4 (EXIT).

Step 6: Stop.
