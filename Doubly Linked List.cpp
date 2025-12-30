// 05_doubly_ll.c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *prev, *next;
} Node;

Node* newNode(int v){
    Node* n=(Node*)malloc(sizeof(Node));
    n->val=v; n->prev=n->next=NULL;
    return n;
}

void traverseForward(Node* head){
    for(Node* cur=head; cur; cur=cur->next) printf("%d ", cur->val);
    printf("\n");
}
void traverseBackward(Node* tail){
    for(Node* cur=tail; cur; cur=cur->prev) printf("%d ", cur->val);
    printf("\n");
}

void insertAt(Node **head, Node **tail, int index, int v){
    Node* n=newNode(v);
    if(*head==NULL){
        *head=*tail=n; return;
    }
    if(index<=0){
        n->next=*head;
        (*head)->prev=n;
        *head=n;
        return;
    }
    Node* cur=*head;
    int i=0;
    while(cur->next && i<index-1){ cur=cur->next; i++; }
    n->next=cur->next;
    n->prev=cur;
    if(cur->next) cur->next->prev=n;
    cur->next=n;
    if(cur==*tail) *tail=n;
}

int deleteByValue(Node **head, Node **tail, int v){
    Node* cur=*head;
    while(cur && cur->val!=v) cur=cur->next;
    if(!cur) return 0;
    if(cur->prev) cur->prev->next=cur->next; else *head=cur->next;
    if(cur->next) cur->next->prev=cur->prev; else *tail=cur->prev;
    free(cur);
    return 1;
}

int main(){
    Node *head=NULL, *tail=NULL;
    insertAt(&head,&tail,0,10);
    insertAt(&head,&tail,1,20);
    insertAt(&head,&tail,2,30);
    insertAt(&head,&tail,1,15);

    printf("Forward: "); traverseForward(head);
    printf("Backward: "); traverseBackward(tail);

    int x;
    printf("Delete value: ");
    scanf("%d",&x);
    if(deleteByValue(&head,&tail,x)) printf("Deleted.\n");
    else printf("Not found.\n");

    printf("Forward: "); traverseForward(head);
    printf("Backward: "); traverseBackward(tail);
    return 0;
}

