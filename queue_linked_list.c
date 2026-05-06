#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*next;
}node;

typedef struct queue{
    node * front;
    node * end;
}queue;

int isempty(queue*q){
    if(q->front==NULL && q->end== NULL){
        return 1;
    }
    return 0;
}

void enqueue(queue * q, int value){
    node *new=(node*)malloc(sizeof(node));
    new->data=value;
    new->next=NULL;

    if(new==NULL){
        printf("memory over");
    }

    else if(isempty(q)){
        q->front =q->end=new;
    }

    else{
        q->end->next=new;
        q->end=new;
    }

}

void dequeue(queue *q){
    if(isempty(q)){
        printf("underflowed");
    }

    else if(q->front->next==NULL){
        node*temp=q->front;
        q->front=q->end=NULL;//reset
        free(temp);

    }
    else{
         node*temp=q->front;
         q->front=q->front->next;
         free(temp);
    }
}

void print(queue *q){
    node * temp=q->front;
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

int main(){
    queue *q=(queue*)malloc(sizeof(queue));
    q->front=q->end=NULL;
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);

    print(q);

    dequeue(q);
    dequeue(q);

    printf("\n");
    print(q);
    return 0;
}