// Simple C program to delete node in a Doubly linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}Node;

Node* create(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("Memory is not allocated\n");
        return NULL;
    }
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;

    return newNode;
}

//Insert at start
void insertAtStart(Node** head,int data){
    Node* temp=create(data);
    if(*head==NULL){
        *head=temp;
        return;
    }
    temp->next=*head;
    (*head)->prev=temp;
    *head=temp;
}

//Insert at End
void insertAtEnd(Node** head,int data){
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
    temp->prev=currentNode;
}

//Insert at given position
void insertAtPosition(Node** head,int position,int data){
    if(*head==NULL){
        printf("List is empty\n");
        return;
    }
    if(position==1){
        insertAtStart(head,data);
        return;
    }
    Node* currentNode=*head;
    int currentPosition=1;
    while((currentPosition<position-1)&&(currentNode!=NULL)){
        currentNode=currentNode->next;
        currentPosition++;
    }
    if(currentNode==NULL){
        printf("can't insert at this position,there are less nodes\n");
        return;
    }
    Node* temp=create(data);
    temp->next=currentNode->next;
    temp->prev=currentNode;
     if(currentNode->next!=NULL){
        currentNode->next->prev=temp; 
    }
    currentNode->next=temp;
}

//Delete at start

void deleteAtStart(Node** head){
    if(*head==NULL){
        printf("list is empty\n");
        return;
    }
    if((*head)->next==NULL){
        free(*head);
        *head=NULL;
        return;
    }
    Node* temp=*head;
    *head=(*head)->next;
    (*head)->prev=NULL;
    free(temp);
}

//Delete at end
void deleteAtEnd(Node** head){
    if(*head==NULL){
        printf("List is empty\n");
        return;
    }
    if((*head)->next==NULL){
        free(*head);
        *head=NULL;
        return;
    }
    Node* currentNode=*head;
    while(currentNode->next!=NULL){
        currentNode=currentNode->next;
    }
    currentNode->prev->next=NULL;
    free(currentNode);
}

//Delete at given position
void deleteAtPosition(Node** head,int position){
    if(*head==NULL){
        printf("list is empty\n");
        return;
    }
    if(position==1){
        deleteAtStart(head);
        return;
    }
    int currentPosition=1;
    Node* currentNode=*head;
    while(currentPosition<position-1 && currentNode!=NULL){
        currentNode=currentNode->next;
        currentPosition++;
    }
    if(currentNode==NULL){
        printf("can't delete at this position,there are less nodes\n");
        return;
    }
    Node* temp=currentNode->next;
    currentNode->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=currentNode;
    }
    free(temp);
    temp=NULL;
}

//Print list
void printList(Node* head){
    if(head==NULL){
        printf("list is empty\n");
        return;
    }
    Node* currentNode=head;
    printf("head->");
    while(currentNode!=NULL){
        printf("%d<->",currentNode->data);
        currentNode=currentNode->next;
    }
    printf("NULL\n");

}

int main(){
    Node* head=NULL;
    insertAtStart(&head,3);
    insertAtStart(&head,5);
    insertAtEnd(&head,7);
    printList(head);
    insertAtPosition(&head,3,100);
    insertAtPosition(&head,1,2);
    printList(head);
    insertAtPosition(&head,6,9);
    printList(head);
    deleteAtStart(&head);
    printList(head);
    deleteAtEnd(&head);
    printList(head);
    deleteAtPosition(&head,4);
    printList(head);

    return 0;
}