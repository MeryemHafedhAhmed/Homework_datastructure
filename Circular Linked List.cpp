// 06_circular_ll.c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node* newNode(int v){
    Node* n=(Node*)malloc(sizeof(Node));
    n->val=v; n->next=NULL;
    return n;
}

// keep a tail pointer for easy ops; head = tail->next when not empty
void insertAfter(Node **tail, int key, int v){
    Node* n=newNode(v);
    if(*tail==NULL){
        n->next=n;
        *tail=n;
        return;
    }
    Node* cur=(*tail)->next; // head
    do{
        if(cur->val==key){
            n->next=cur->next;
            cur->next=n;
            if(cur==*tail) *tail=n;
            return;
        }
        cur=cur->next;
    } while(cur!=(*tail)->next);

    // if key not found, insert after tail (append)
    n->next=(*tail)->next;
    (*tail)->next=n;
    *tail=n;
}

int deleteValue(Node **tail, int v){
    if(*tail==NULL) return 0;
    Node* prev=*tail;
    Node* cur=(*tail)->next;

    do{
        if(cur->val==v){
            if(cur==prev){ // only one node
                free(cur);
                *tail=NULL;
                return 1;
            }
            prev->next=cur->next;
            if(cur==*tail) *tail=prev;
            free(cur);
            return 1;
        }
        prev=cur;
        cur=cur->next;
    } while(cur!=(*tail)->next);

    return 0;
}

void traverse(Node *tail){
    if(!tail){ printf("(empty)\n"); return; }
    Node* head=tail->next;
    Node* cur=head;
    do{
        printf("%d ", cur->val);
        cur=cur->next;
    } while(cur!=head);
    printf("\n");
}

int main(){
    Node* tail=NULL;
    insertAfter(&tail, -1, 10);
    insertAfter(&tail, 10, 20);
    insertAfter(&tail, 20, 30);
    insertAfter(&tail, 10, 15);

    printf("List: "); traverse(tail);

    int x;
    printf("Delete value: ");
    scanf("%d",&x);
    if(deleteValue(&tail,x)) printf("Deleted.\n");
    else printf("Not found.\n");

    printf("List: "); traverse(tail);
    return 0;
}

