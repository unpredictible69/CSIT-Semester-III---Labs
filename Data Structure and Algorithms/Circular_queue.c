#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int count=0; // a global counter to keep track of the queue size
struct Circular_Queue
{
  int front,rear,max_size;
  int *queued_data;
};
void Enqueue(struct Circular_Queue *cq)
{
  if(count==cq->max_size)
  {
    printf("Queue is full!\n");
  }
  else
  {
    int data;
    printf("Enter data: ");
    scanf("%d",&data);
    cq->rear=(cq->rear+1)%cq->max_size;
    cq->queued_data[cq->rear]=data;
    printf("%d queued to the queue\n",cq->queued_data[cq->rear]);
    count++;
  }
}
void Dequeue(struct Circular_Queue *cq)
{
  if(count==0)
  {
    printf("Queue is empty!\n");
  }
  else
  {
    printf("%d dequeued from the queue\n",cq->queued_data[cq->front]);
    cq->front = (cq-> front+1)%cq->max_size;
    count--;
  }
}
void Display_Queue(struct Circular_Queue *cq)
{
  if(count==0)
  {
    printf("Queue is empty, cannot display! Enqueue data first!\n");
  }
  else
  {
    printf("front->\t");
    int i=0;
    int index= cq->front;
    while(i<count)
    {
      printf("%d\t",cq->queued_data[index]);
      index=(index+1)%cq->max_size;
      i++;
    }
    printf("<-rear\n");
  }
}
int main (void)
{
  struct Circular_Queue *cq;
  int continue_init;
  error_handler:
  printf("Initialize memory?(press 1)\tQuit program(press 0): ");
if(scanf("%d",&continue_init) != 1)
{
    printf("Invalid input! Please enter 0 or 1.\n");
    while(getchar()!='\n');   // clear input buffer
    goto error_handler;
}

if(continue_init != 0 && continue_init != 1)
{
    printf("Invalid choice! Please enter 0 or 1.\n");
    goto error_handler;
}
if(continue_init == 0)
{
    printf("Exiting with users choice.\n");
    return -1;
}
  memory_initialization:
  cq=calloc(1,sizeof(struct Circular_Queue));
if(cq == NULL)
{
    printf("Memory allocation failed!\n");
    goto error_handler;
}
  cq->front = 0;
cq->rear = -1;
  printf("Enter the size of queue: ");
  scanf("%d",&cq->max_size);
  if(cq->max_size <= 0)
{
    printf("Invalid queue size!\n");
    free(cq);
    goto error_handler;
}
  cq->queued_data=calloc(cq->max_size,sizeof(int));
if(cq->queued_data == NULL)
{
    free(cq);
    printf("Memory allocation failed!\n");
    goto error_handler;
}
  printf("---Circular Queue ----\n");
  while(1)
  {
    int choice;
    printf("Operations:\n1.Enqueue\t\t2.Dequeue\n3.Display\t\t4.Exit.\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        Enqueue(cq);
        break;
      case 2:
        Dequeue(cq);
        break;
      case 3:
        Display_Queue(cq);
        break;
      case 4:
        printf("Exiting the program.\n");
        free(cq->queued_data);
        free(cq);
        return 0;
      default:
        printf("Invalid Input! Choose from 1 to 4 only!\n");
        break;
      }
  }
}
