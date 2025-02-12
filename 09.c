#include <stdio.h>
#include <string.h>

int main() {
    int n, srcRouter, i, j, k, w, v, min;
    
    int costMatrix[100][100], dist[100], last[100];
    int vis[100];
    
    printf("Enter the no of routers : \n");
    scanf("%d", &n);
    
    printf("Enter the cost matrix values : \n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++){
            printf("\n%d -> %d : ", i, j);
            scanf("%d", &costMatrix[i][j]);
            if(costMatrix[i][j] < 0) {
                costMatrix[i][j] = 1000;
            }
        }
    }
    
    printf("\n");
    printf("Enter the source router: \n");
    scanf("%d", &srcRouter);
    
    for(v = 0; v < n; v++) {
        vis[v] = 0;
        last[v] = srcRouter;
        dist[v] = costMatrix[srcRouter][v];
    }
        
    vis[srcRouter] = 1;
    for(i = 0; i < n; i++) {
        min = 1000;
        for(w = 0; w < n; w++) {
            if(!vis[w]) {
                if(dist[w] < min) {
                    v = w;
                    min = dist[w];
                }
            }
        }
        
        vis[v] = 1;
        for(w = 0; w < n; w++) {
            if(!vis[w]) {
                if(min + costMatrix[v][w] < dist[w]) {
                    dist[w] = min + costMatrix[v][w];
                    last[w] = v;
                }
            }
        }
    }
    
    for(i = 0; i < n; i++) {
        printf("%d ==> %d : Path taken : %d", srcRouter, i, i);
        w = i;
        while(w != srcRouter) {
            printf("\n<-- %d",last[w]);
            w = last[w];
        }
        printf("\nShortest path cost : %d\n",dist[i]);
    }
}
