// Simple C program to create a Doubly linked list

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
    newnode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;

    return newNode;
}
int main(){
    Node* temp=create(10);
}