// 01_sparse_matrix.c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int r, c, v;
} Triple;

int main() {
    int rows, cols;
    printf("Enter rows cols: ");
    if (scanf("%d %d", &rows, &cols) != 2) return 0;

    int **A = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) A[i] = (int*)malloc(cols * sizeof(int));

    printf("Enter matrix values (%dx%d):\n", rows, cols);
    int nnz = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            scanf("%d", &A[i][j]);
            if (A[i][j] != 0) nnz++;
        }

    // Dense -> Sparse (COO)
    Triple *S = (Triple*)malloc(nnz * sizeof(Triple));
    int k = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (A[i][j] != 0) {
                S[k].r = i; S[k].c = j; S[k].v = A[i][j];
                k++;
            }

    printf("\nSparse (COO) triples (row col val):\n");
    for (int i = 0; i < nnz; i++)
        printf("%d %d %d\n", S[i].r, S[i].c, S[i].v);

    // Transpose sparse (simple)
    Triple *T = (Triple*)malloc(nnz * sizeof(Triple));
    for (int i = 0; i < nnz; i++) {
        T[i].r = S[i].c;
        T[i].c = S[i].r;
        T[i].v = S[i].v;
    }

    printf("\nTransposed triples (row col val):\n");
    for (int i = 0; i < nnz; i++)
        printf("%d %d %d\n", T[i].r, T[i].c, T[i].v);

    // Sparse -> Dense (rebuild original)
    int **B = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        B[i] = (int*)calloc(cols, sizeof(int));
    }
    for (int i = 0; i < nnz; i++) {
        B[S[i].r][S[i].c] = S[i].v;
    }

    printf("\nRebuilt dense matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) printf("%d ", B[i][j]);
        printf("\n");
    }

    // free
    for (int i = 0; i < rows; i++) { free(A[i]); free(B[i]); }
    free(A); free(B);
    free(S); free(T);
    return 0;
}

