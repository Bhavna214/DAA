# include <stdio.h>
# include <math.h>

int main(){
    int i, j, n;
    int a[n][n];
    printf("Enter the number of queens:");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        for(j=0;j<n;j++){
            a[i][j]=".";
        }
    }
    return 0;
}