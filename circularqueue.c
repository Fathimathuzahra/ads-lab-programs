
#include<stdio.h>
#include<stdlib.h>
#define max 10
int insq(int cqueue[max],int*front,int*rear,int*data)
{
if((*rear + 1) % max == *front)
return(-1);
else
{
*rear=(*rear + 1) % max;
cqueue[*rear]=*data;
return(1);
}
}
int delq(int cqueue[max],int *front,int *rear,int *data)
{
if(*front == *rear)
return(-1);
else
{
*front=(*front +1) % max;
*data=cqueue[*front];
return 1;
}
}
int main()
{
int cqueue[max],data;
int front,rear,reply,ch;
front=rear=0;
printf("\n 1.insert number in circular queue");
printf("\n 2.delete number in circular queue");
printf("\nExit\n");
while(1)
{
printf("choose operation:");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nEnter number:");
scanf("%d",&data);
reply=insq(cqueue,&front,&rear,&data);
if(reply == -1)
printf("\nCircular queue is full\n");
else
printf("%d is inserted in a circular queue\n\n",data);
break;
case 2:
reply=delq(cqueue,&front,&rear,&data);
if(reply == -1)
printf("\nCIRC:ULARR QUEUE IS empty");
else
printf("\n %d is deleted from circular queue\n",data);
printf("\n");
break;
case 3:exit(0);
default:printf("Invalid operation\n");
}
}
return 0;
}

     
              