// Simple C program to insert node for singly linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* create(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("Memory is not allocated");
        return NULL;
    }
    newNode->data=data;
    newNode->next=NULL;

    return newNode;
}

//Insert at start

void insertAtStart(int data,Node** head){
    Node* temp=create(data);
    if(*head==NULL){
        *head=temp;
        return;
    }
    temp->next=*head;
    *head=temp;
}

//Insert at End

void insertAtEnd(int data,Node** head){
    Node* temp=create(data);
    if(*head==NULL){
        *head=temp;
        return;
    }
    Node* currentNode=*head;
    while(currentNode->next!=NULL){
        currentNode=currentNode->next;
    }
    currentNode->next=temp;
}

//Insert at given position 

void insertAtPosition(int data,Node** head,int position){
    if(*head==NULL){
        printf("List is empty");
        return;
    }
    if(position==1){
        insertAtStart(data,head);
        return;
    }
    Node* currentNode=*head;
    int currentPosition=1;
    while((currentPosition<position-1)&&(currentNode!=NULL))
    {
        currentPosition++;
        currentNode=currentNode->next;
    }
    if(currentNode==NULL){
        printf("can't insert at this position,there are less nodes");
        return;
    }
    Node* temp=create(data);
    temp->next=currentNode->next;
    currentNode->next=temp;
}

//Print list

void printList(Node* head){
    Node* currentNode=head;
    if(head==NULL){
        printf("No elements to display");
    }
    printf("\nhead->");
    while(currentNode!=NULL){
        printf("%d->",currentNode->data);
        currentNode=currentNode->next;
    }
    printf("NULL\n");
}

int main(){
    Node* head=NULL;
    head=create(10);
    insertAtStart(2,&head);
    insertAtStart(3,&head);
    insertAtStart(1,&head);
    printList(head);
    insertAtEnd(5,&head);
    printList(head);
    insertAtPosition(100,&head,3);
    printList(head);
}