#include <stdio.h>

int main() {
    int n = 4;
    int cables[4][2] = {{0,1},{0,3},{1,2},{1,3}};
    int adj_matrix[n][n];
    int max_rank = 0;
    
    // initialize adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj_matrix[i][j] = 0;
        }
    }
    
    // populate adjacency matrix
    for (int i = 0; i < n; i++) {
        int a = cables[i][0];
        int b = cables[i][1];
        adj_matrix[a][b] = 1;
        adj_matrix[b][a] = 1;
    }
    
    // calculate max rank
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int rank = 0;
            for (int k = 0; k < n; k++) {
                if (adj_matrix[i][k] || adj_matrix[j][k]) {
                    rank++;
                }
            }
            if (rank > max_rank) {
                max_rank = rank;
            }
        }
    }
    
    printf("%d\n", max_rank);
    return 0;
}
