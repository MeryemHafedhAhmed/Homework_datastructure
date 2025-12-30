// 07_array_ops.c
#include <stdio.h>

void insertAt(int arr[], int *n, int cap, int idx, int val){
    if(*n>=cap){ printf("Full\n"); return; }
    if(idx<0) idx=0;
    if(idx>*n) idx=*n;
    for(int i=*n; i>idx; i--) arr[i]=arr[i-1];
    arr[idx]=val;
    (*n)++;
}

void deleteAt(int arr[], int *n, int idx){
    if(*n<=0){ printf("Empty\n"); return; }
    if(idx<0 || idx>=*n){ printf("Invalid index\n"); return; }
    for(int i=idx; i<*n-1; i++) arr[i]=arr[i+1];
    (*n)--;
}

int main(){
    int cap=100, arr[100], n;
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter %d elements:\n", n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    int idx,val;
    printf("Insert (idx val): ");
    scanf("%d %d",&idx,&val);
    insertAt(arr,&n,cap,idx,val);

    printf("After insert: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");

    printf("Delete index: ");
    scanf("%d",&idx);
    deleteAt(arr,&n,idx);

    printf("After delete: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}

