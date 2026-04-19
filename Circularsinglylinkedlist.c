// A simple program to implements a Circular singly linked list using C

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* create(int data){
    Node* newNode=(Node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory is not allocate\n");
        return NULL;
    }
    newNode->data=data;
    newNode->next=NULL;

    return newNode;
}

void insertAtStart(Node** tail,int data){
    Node* temp=create(data);
    if(*tail==NULL){
        temp->next=temp;
        *tail=temp;
        return;
    }
    temp->next=(*tail)->next;
    (*tail)->next=temp;
}

void insertAtTail(Node** tail,int data){
    Node* temp=create(data);
    if(*tail==NULL){
        temp->next=temp;
        *tail=temp;
        return;
    }
    temp->next=(*tail)->next;
    (*tail)->next=temp;
    *tail=temp;
}

void deleteAtStart(Node** tail){
    if(*tail==NULL){
        printf("list is empty\n");
        return;
    }
    if((*tail)->next==(*tail)){
        free(*tail);
        *tail=NULL;
        return;
    }
    Node* temp=(*tail)->next;
    (*tail)->next=temp->next;
    free(temp);
    temp=NULL;
}

void deleteAtEnd(Node** tail){
    if(*tail==NULL){
        printf("list is empty\n");
        return;
    }
    if((*tail)->next==(*tail)){
        free(*tail);
        *tail=NULL;
        return;
    }
    Node* currentNode=(*tail)->next;
    while(currentNode->next!=*tail){
        currentNode=currentNode->next;
    }
    currentNode->next=(*tail)->next;
    free(*tail);
    *tail=currentNode;
}

void printList(Node* tail){
    if(tail==NULL){
        printf("list is empty");
        return;
    }
    Node* currentNode=tail->next;
    do{
        printf("%d->",currentNode->data);
        currentNode=currentNode->next;

    }while(currentNode!=tail->next);
    printf("\n");
}

int main(){
    int choice,data;
    Node* tail=NULL;
    while(1){
        printf("\n-----Circular singly linked list demo-----\n");
        printf("1.Insert a node at start\n");
        printf("2.Insert a node at end\n");
        printf("3.Delete a node at start\n");
        printf("4.Delete a node at end\n");
        printf("5.print list\n");
        printf("6.Exit\n\n");

        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter a data:");
                scanf("%d",&data);
                insertAtStart(&tail,data);
                break;
            }
            case 2:{
                printf("Enter a data:");
                scanf("%d",&data);
                insertAtTail(&tail,data);
                break;
            }
            case 3:{
                deleteAtStart(&tail);
                break;
            }
            case 4:{
                deleteAtEnd(&tail);
                break;
            }
            case 5:{
                printf("Elements of the list:");
                printList(tail);
                break;
            }
            case 6:{
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