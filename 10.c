#include <stdio.h>

int main() {
    int n;
    int i, j, k;
    
    int a[10][10],b[10][10];
    
    printf("\n Enter the number of nodes:");
    scanf("%d", &n);
    
    for(i = 0;i < n; i++) {
        for(j=0; j < n; j++) {
            printf("\n Enter the distance between the host %d - %d:",i+1,j+1);
            scanf("%d", &a[i][j]);
        }
    }
    
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(a[i][j] > a[i][k] + a[k][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }
    
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            b[i][j] = a[i][j];
            if(i == j) {
                b[i][j] = 0;
            }
        }
    }
    
    printf("\n The output matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
