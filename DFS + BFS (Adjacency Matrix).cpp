// 09_dfs_bfs.c
#include <stdio.h>

#define MAXN 200

void dfsRec(int n, int g[MAXN][MAXN], int u, int visited[]){
    visited[u]=1;
    printf("%d ", u);
    for(int v=0; v<n; v++){
        if(g[u][v] && !visited[v]) dfsRec(n,g,v,visited);
    }
}

void bfs(int n, int g[MAXN][MAXN], int start){
    int visited[MAXN]={0};
    int q[MAXN], front=0, back=0;
    visited[start]=1;
    q[back++]=start;

    while(front<back){
        int u=q[front++];
        printf("%d ", u);
        for(int v=0; v<n; v++){
            if(g[u][v] && !visited[v]){
                visited[v]=1;
                q[back++]=v;
            }
        }
    }
}

int main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    int g[MAXN][MAXN];
    printf("Enter adjacency matrix (%dx%d):\n", n,n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&g[i][j]);

    int start;
    printf("Start vertex: ");
    scanf("%d",&start);

    int visited[MAXN]={0};
    printf("DFS: ");
    dfsRec(n,g,start,visited);
    printf("\n");

    printf("BFS: ");
    bfs(n,g,start);
    printf("\n");
    return 0;
}

