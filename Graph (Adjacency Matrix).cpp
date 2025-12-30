// 08_graph_clusters.c
#include <stdio.h>

#define MAXN 200

int main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int g[MAXN][MAXN];
    printf("Enter adjacency matrix (%dx%d):\n", n, n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&g[i][j]);

    int visited[MAXN]={0};
    int queue[MAXN];

    int comp=0;
    for(int s=0;s<n;s++){
        if(visited[s]) continue;

        // BFS to get one component
        int front=0, back=0;
        queue[back++]=s;
        visited[s]=1;

        printf("Cluster %d: ", ++comp);

        while(front<back){
            int u=queue[front++];
            printf("%d ", u);

            for(int v=0; v<n; v++){
                if(g[u][v] && !visited[v]){
                    visited[v]=1;
                    queue[back++]=v;
                }
            }
        }
        printf("\n");
    }
    return 0;
}

