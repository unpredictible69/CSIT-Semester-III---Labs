#include <stdio.h>
#include <stdlib.h>

struct Circular_Queue
{
  int front;
  int rear;
  int max_size;
  int count;
  int *queued_data;
};

void Enqueue(struct Circular_Queue *cq)
{
  if (cq->count == cq->max_size)
  {
    printf("Queue is full!\n");
    return;
  }
  int data;
  printf("Enter data: ");
  if (scanf("%d", &data) != 1)
  {
    printf("Invalid input! Numbers only.\n");
    while (getchar() != '\n')
      ;
    return;
  }

  cq->rear = (cq->rear + 1) % cq->max_size;
  cq->queued_data[cq->rear] = data;
  printf("%d queued to the queue.\n", cq->queued_data[cq->rear]);
  cq->count++;
}

void Dequeue(struct Circular_Queue *cq)
{
  if (cq->count == 0)
  {
    printf("Queue is empty!\n");
    return;
  }
  printf("%d dequeued from the queue.\n", cq->queued_data[cq->front]);
  cq->front = (cq->front + 1) % cq->max_size;
  cq->count--;
}

void Display_Queue(struct Circular_Queue *cq)
{
  if (cq->count == 0)
  {
    printf("Queue is empty, cannot display! Enqueue data first!\n");
    return;
  }
  printf("front->\t");
  int index = cq->front;
  for (int i = 0; i < cq->count; i++)
  {
    printf("%d\t", cq->queued_data[index]);
    index = (index + 1) % cq->max_size;
  }
  printf("<-rear\n");
}

int main(void)
{
  struct Circular_Queue *cq = NULL;
  int continue_init;
  while (1)
  {
    printf("Initialize memory?(press 1)\tQuit program(press 0): ");
    if (scanf("%d", &continue_init) != 1)
    {
      printf("Invalid input! Please enter 0 or 1.\n");
      while (getchar() != '\n')
        ;
      continue;
    }

    if (continue_init == 0)
    {
      printf("Exiting with users choice.\n");
      return 0;
    }
    else if (continue_init == 1)
    {
      break;
    }
    else
    {
      printf("Invalid choice! Please enter 0 or 1.\n");
    }
  }
  cq = calloc(1, sizeof(struct Circular_Queue));
  if (cq == NULL)
  {
    printf("Memory allocation failed!\n");
    return -1;
  }

  while (1)
  {
    printf("Enter the size of the queue: ");
    if (scanf("%d", &cq->max_size) != 1 || cq->max_size <= 0)
    {
      printf("Invalid queue size! Must be a positive number.\n");
      while (getchar() != '\n')
        ;
      continue;
    }
    break;
  }
  cq->front = 0;
  cq->rear = -1;
  cq->count = 0;
  cq->queued_data = calloc(cq->max_size, sizeof(int));
  if (cq->queued_data == NULL)
  {
    printf("Memeory allocation failed!\n");
    free(cq);
    return -1;
  }

  printf("--- Circular Queue ---\n");
  while (1)
  {
    int choice;
    printf("Enter your choice of operation:\n");
    printf("1.Enqueue\t\t2.Dequeue\n3.Display\t\t4.Exit\n");
    if (scanf("%d", &choice) != 1)
    {
      printf("Invalid input!");
      while (getchar() != '\n')
        ;
      continue;
    }

    switch (choice)
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
      printf("Exiting program.\n");
      free(cq->queued_data);
      free(cq);
      return 0;
    default:
      printf("Invalid range of input. Please choose operation 1-4 only!\n");
    }
  }
}