#include<stdio.h>
// simple stack operaiton initiation
#define STACK_MAX_SIZE 20 // global variable to store the maximum size of the stack
struct stack_operations
{
    int top; // variable to keep track of the top index of the stack
    int stacked_data[STACK_MAX_SIZE]; // array to store the items in the stack
};
void stack_push(struct stack_operations *s) // function to push an item onto the stack
{
    if(s->top == STACK_MAX_SIZE -1) // check if the stack is full
    {
        printf("Stack overflow! Cannot push more items onto the stack.\n");
        return;
    }
    else 
    {
        int data; // variable to store the data to be pushed onto the stack
        printf("Enter the stack data to be pushed: ");
        scanf("%d", &data); // read the data to be pushed from user
        s->top = s->top +1; // increment the top index
        s->stacked_data[s->top] = data; // add the data to the stack
    }
}
void stack_pop(struct stack_operations *s) // function to pop an item from the stack
{
    if(s->top == -1) // check if the stack is empty
    {
        printf("Stack underflow! Cannot pop items from an empty stack.\n");
        return;
    }
    else 
    {
        int popped_data = s->stacked_data[s->top]; //grep data to be popped from the top of the stacked data
        s->top = s->top -1; // decrement the top index
        printf("Popped data: %d\n", popped_data); // print the popped data
    }
}
void show_stacked_data(struct stack_operations *s) // function to display the items in the stack
{
    if(s->top == -1) // check if the stack is empty
    {
        printf("Stack is empty! No items to display.\n");
        return;
    }
    else 
    {
        printf("Stacked data: ");
        for(int i=s->top; i>=0; i--) //loop from top to the end of the stack
        {
            printf("%d", s->stacked_data[i]); // print each item in the stacked data
        }
        printf("\n"); // print a new line after displaying the stacked data
        printf("Top of stack: %d\n", s->stacked_data[s->top]); // print the top item of the stack
        printf("Stack size: %d\n", s->top +1); // print the current size of the stack
    }
}
int main (void)
{
    struct stack_operations s; // create an instance of the stack_operations structure
    s.top = -1; // initialize the top index to -1, initializing an empty stack for the start of the operation
    int choice; // variable to store the user's choice for stack operations
    while (1) // infinite loop to continuously prompt the user for stack operations until they choose to exit
    {
        printf("Choose an operation:\n1.Push\t2.Pop\t3.Show Stack\t4.Exit\n");
        scanf("%d", &choice); // read the user's choice for stack operation
        switch (choice) // switch case to perform the chosen stack operation
        {
            case 1:
                stack_push(&s); // call the stack_push function to push an item onto the stack
                break;
            case 2:
                stack_pop(&s); // call the stack_pop function to pop an item from the stack
                break;
            case 3:
                show_stacked_data(&s); // call the show_stacked_data function to display the items in the stack
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0; // exit the program
            default:
                printf("Invalid choice! Please choose a valid operation.\n");
        }
    }
    
}