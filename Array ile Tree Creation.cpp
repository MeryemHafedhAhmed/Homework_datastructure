// 10_tree_from_array.c
#include <stdio.h>

#define MAXN 1000
#define NIL -999999

void preorder(int arr[], int n, int i){
    if(i>=n || arr[i]==NIL) return;
    printf("%d ", arr[i]);
    preorder(arr,n,2*i+1);
    preorder(arr,n,2*i+2);
}
void inorder(int arr[], int n, int i){
    if(i>=n || arr[i]==NIL) return;
    inorder(arr,n,2*i+1);
    printf("%d ", arr[i]);
    inorder(arr,n,2*i+2);
}
void postorder(int arr[], int n, int i){
    if(i>=n || arr[i]==NIL) return;
    postorder(arr,n,2*i+1);
    postorder(arr,n,2*i+2);
    printf("%d ", arr[i]);
}

int main(){
    int n;
    printf("Enter array size for tree: ");
    scanf("%d",&n);

    int arr[MAXN];
    printf("Enter %d values (use %d for empty node):\n", n, NIL);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    printf("Preorder: "); preorder(arr,n,0); printf("\n");
    printf("Inorder: "); inorder(arr,n,0); printf("\n");
    printf("Postorder: "); postorder(arr,n,0); printf("\n");
    return 0;
}

