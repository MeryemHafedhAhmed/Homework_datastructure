// 04_heaps.c
#include <stdio.h>
#include <stdlib.h>

#define CAP 1000

typedef struct {
    int a[CAP];
    int size;
    int isMin; // 1=minheap, 0=maxheap
} Heap;

int better(Heap *h, int x, int y){
    return h->isMin ? (x < y) : (x > y);
}

void heapInit(Heap *h, int isMin){ h->size=0; h->isMin=isMin; }

void swap(int *x,int *y){ int t=*x;*x=*y;*y=t; }

void heapifyUp(Heap *h, int i){
    while(i>0){
        int p=(i-1)/2;
        if(better(h, h->a[i], h->a[p])) { swap(&h->a[i], &h->a[p]); i=p; }
        else break;
    }
}

void heapifyDown(Heap *h, int i){
    while(1){
        int l=2*i+1, r=2*i+2, best=i;
        if(l<h->size && better(h, h->a[l], h->a[best])) best=l;
        if(r<h->size && better(h, h->a[r], h->a[best])) best=r;
        if(best!=i){ swap(&h->a[i], &h->a[best]); i=best; }
        else break;
    }
}

void insert(Heap *h, int x){
    if(h->size>=CAP){ printf("Heap full\n"); return; }
    h->a[h->size]=x;
    heapifyUp(h, h->size);
    h->size++;
}

int peek(Heap *h){
    if(h->size==0){ printf("Empty heap\n"); return 0; }
    return h->a[0];
}

int extractRoot(Heap *h){
    if(h->size==0){ printf("Empty heap\n"); return 0; }
    int root=h->a[0];
    h->a[0]=h->a[h->size-1];
    h->size--;
    heapifyDown(h,0);
    return root;
}

void printHeap(Heap *h){
    for(int i=0;i<h->size;i++) printf("%d ", h->a[i]);
    printf("\n");
}

int main(){
    Heap minH, maxH;
    heapInit(&minH, 1);
    heapInit(&maxH, 0);

    int n;
    printf("How many numbers? ");
    scanf("%d",&n);
    printf("Enter numbers:\n");
    for(int i=0;i<n;i++){
        int x; scanf("%d",&x);
        insert(&minH,x);
        insert(&maxH,x);
    }
    printf("MinHeap array: "); printHeap(&minH);
    printf("MaxHeap array: "); printHeap(&maxH);

    printf("Min peek=%d, extract=%d\n", peek(&minH), extractRoot(&minH));
    printf("Max peek=%d, extract=%d\n", peek(&maxH), extractRoot(&maxH));
    return 0;
}

