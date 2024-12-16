#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node *prev, *next;
};
struct node *start = NULL;
void traverse()
{
if(start == NULL)
{
printf("\nList is empty\n");
return;
}
struct node *temp;
temp = start;
while(temp != NULL)
{
printf("Data = %d\n", temp->info);
temp = temp->next;
}
}
void insertbeginning()
{
int data;
struct node *temp;
temp = (struct node*)malloc(sizeof(struct node));
printf("\nEnter number to be inserted: ");
scanf("%d", &data);
temp->info = data;
temp->prev = NULL;
temp->next = start;
start = temp;
}
void insertend()
{
int data;
struct node *temp, *trav;
temp = (struct node*)malloc(sizeof(struct node));
temp->prev = NULL;
temp->next = NULL;
printf("\nEnter number to be inserted: ");
scanf("%d", &data);
temp->info = data;
temp->next = NULL;
trav = start;
if(start == NULL)
{
start = temp;
}
else{
while(trav->next != NULL)
trav = trav->next;
temp->prev = trav;
trav->next = temp;
}
}
void insertposition()
{
int data, pos, i = 1;
struct node *temp, *newnode;
newnode = malloc(sizeof(struct node));
newnode->next = NULL;
newnode->prev = NULL;
printf("\nEnter the position : ");
scanf("%d",&pos);
if(start == NULL)
{
start = newnode;
newnode->prev = NULL;
newnode->next = NULL;
}
else if(pos == 1)
{
insertbeginning();
}
else{
printf("\nEnter the number: ");
scanf("%d",&data);
newnode->info = data;
temp = start;
while(i < pos -1)
{
temp = temp->next;
i++;
}
newnode->next = temp->next;
newnode->prev = temp;
temp->next = newnode;
temp->next->prev = newnode;
}
}
void deletefirst()
{
struct node *temp;
if(start == NULL)
printf("\nList is empty");
else{
temp = start;
start= start->next;
if(start != NULL)
start->prev = NULL;
free(temp);
}
}

void deleteend()
{
struct node *temp;
if(start == NULL)
printf("\nList is empty");
temp = start;
while (temp->next != NULL)
temp = temp->next;
if(start->next == NULL)
start = NULL;
else
{
temp->prev->next = NULL;
free(temp);
}
}
void deleteposition()
{
int pos, i = 1;
struct node *temp, *position;
temp=start;
if(start == NULL)
printf("\nlist is empty\n");
else
{
printf("Enter position : ");
scanf("%d",&pos);
if(pos == 1)
{
deletefirst();
if(start != NULL)
{
start->prev = NULL;
}
free(position);
return;
}
while(i < pos - 1)
{
temp = temp->next;
i++;
}
position = temp->next;
if(position->next != NULL)
 position->next->prev = temp;
temp->next = position->next;
free(position);
}
}
int main()
{
int choice;
while (1) {
printf("\n\t1 To see the list\n");
printf("\t2 for insertbeginning\n");
printf("\t3 for insert at5 end\n");
printf("\t4 for insert at position\n");
printf("\t5 for delete at first\n");
printf("\t6 for delete at any position\n");
printf("\t7 for delete at end\n");
printf("8 to exit\n");
printf("\nEnter choice :\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
traverse();
break;

case 2:
insertbeginning();
break;

case 3:
insertend();
break;

case 4:
insertposition();
break;

case 5:
deletefirst();
break;

case 6:
deleteposition();
break;

case 7:
deleteend();
break;

case 8:
exit(1);
break;

default:
printf("incorrect choice.Try again\n");
continue;
}
}
return 0;
}



                                     
      