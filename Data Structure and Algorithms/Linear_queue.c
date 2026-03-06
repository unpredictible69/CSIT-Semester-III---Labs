#include <stdio.h>
#include <stdlib.h>
struct Linear_Queue
{
    int front;
    int rear;
    int max_size;
    int *queued_data;
};
void enqueue(struct Linear_Queue *q)
{
    if (q-> rear == q->max_size - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        int data;
        printf("Enter the data to be enqueued: ");
        scanf("%d", &data);
        q-> rear++;
        q-> queued_data[q-> rear] = data;
        printf("%d enqueued to rear.\n", q->queued_data[q->rear]);
    }
}
void dequeue(struct Linear_Queue *q)
{
  if (q-> front > q->rear)
  {
    printf("Queue is already empty. Cannot Dequeue!\n");
  }
  else
  {
    printf("%d dequeued from the queue.\n",q->queued_data[q->front]);
    q->front++;
  }
}
void display_queue(struct Linear_Queue *q)
{
  printf("front-> ");
  int i=q->front;
  while(i<=q->rear)
  {
    printf("%d ->",q->queued_data[i]);
    i++;
  }
  printf("rear\n");
}
int main(void)
{
  struct Linear_Queue *q;
  queue_allocate_memory: //check the valid size of queue so that our program initializes correctly
  q=malloc(sizeof(struct Linear_Queue));
   if(q==NULL)
  {
    printf("Memory allocation failed!");
    goto queue_allocate_memory;
  }
    q->front=0;
  q->rear=-1;
  printf("Enter the maximum size of the queue: ");
  while(scanf("%d",&q->max_size)!=1 || q->max_size <=0)
  {
    printf("Invalid queue size!\n");
    while(getchar()!='\n');
  }
  q->queued_data=calloc(q->max_size,sizeof(int));
  if(q->queued_data==NULL)
  {
    printf("Memory allocation failed!");
    free(q);
    goto queue_allocate_memory;
  }
  while(1)
  {
    printf("\nQueue Operations:\n1.Enqueue\t\t2.Dequeue\n3.Display queue\t\t4.Exit\nEnter your choice: ");
    int choice;
    read_input_choice:
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        enqueue(q);
        break;
      case 2:
        dequeue(q);
        break;
      case 3:
        display_queue(q);
        break;
      case 4:
        printf("Exiting.....\n");
        free(q->queued_data);
        free(q);
        return 0;
      default:
        printf("Invalid choice!");
        goto read_input_choice;
    }
  }
  }
