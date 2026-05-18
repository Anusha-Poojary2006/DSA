//A simple program for stack operations in C

#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100

typedef struct stack{
    int items[MAX_STACK_SIZE];
    int index;
}Stack;

void initialize(Stack* pStack){
    pStack->index=-1;
    printf("\n Stack initialized");
}

int push(int data,Stack* pStack){
    if(pStack->index==MAX_STACK_SIZE-1){
        printf("Stack Oveflow\n");
        return -1;
    }
    pStack->index+=1;
    pStack->items[pStack->index]=data;
    printf("Pushed value %d to the stack",data);
}

int pop(Stack* pStack){
    if(pStack->index==-1){
        printf("Stack underflow\n");
        return -1;
    }
    int item=pStack->items[pStack->index];
    pStack->index-=1;
    printf("Popped value %d in the stack\n",item);
    return item;
}

int peek(Stack* pStack){
    if(pStack->index==-1){
        printf("stack is empty\n");
        return -1;
    }
    printf("\n Top element in the stack is %d\n",pStack->items[pStack->index]);
    return pStack->items[pStack->index];
}

int getSize(Stack* pStack){
    if(pStack->index==-1){
        printf("stack is empty\n");
        return -1;
    }
    printf("\n current number of elements in the stack is %d\n",pStack->index+1);
    return pStack->index+1;
}

int main(){
    int choice,data;
    Stack myStack;
    initialize(&myStack);
    while(1){
        printf("\n-----Stack demo-----\n");
        printf("1.Push elements to the stack\n");
        printf("2.Pop elements from the stack\n");
        printf("3.get size of the stack\n");
        printf("4.get top element in the stack\n");
        printf("5.Exit\n\n");

        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter data to push:\n");
                scanf("%d",&data);
                push(data,&myStack);
                break;
            }
            case 2:{
                int item=pop(&myStack);
                break;
            }
            case 3:{
                int numOfItemsInStack=getSize(&myStack);
                break;
            }
            case 4:{
                int topElement=peek(&myStack);
                break;
            }
            case 5:{
                exit(0);
                break;
            }
            default:{
                printf("Enter a valid choice");
                break;
            }
       }
    }
    return 0;
}
