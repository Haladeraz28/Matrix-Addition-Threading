#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
struct data {
    int i;
    int j;
};

int i, j, m, n;
int ** A;
int ** B;
int ** C;
void * addition(void * args) {
    struct data * data = args;
    C[data-> i][data-> j] = A[data-> i][data-> j] + B[data-> i][data-> j];
}
void main() {    
    printf("Enter Arrays Dimensions (Row Column) : \n");
    scanf("%d %d", & m, & n);
    A = (int ** ) malloc(m * sizeof(int ** ));
    for (i = 0; i < m; i++) A[i] = (int * ) malloc(n * sizeof(int));

    B = (int ** ) malloc(m * sizeof(int ** ));
    for (i = 0; i < m; i++) B[i] = (int * ) malloc(n * sizeof(int));

    C = (int ** ) malloc(m * sizeof(int ** ));
    for (i = 0; i < m; i++) C[i] = (int * ) malloc(n * sizeof(int));

    printf("Enter First Array = \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", & A[i][j]);
        }
        printf("\n");
    }
    printf("Enter Second Array = \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", & B[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            pthread_t tid;
            struct data * data = (struct data * ) malloc(sizeof(struct data));
            data-> i = i;
            data-> j = j;
            pthread_create( & tid, NULL, addition, data);
            pthread_join(tid, NULL);
        }
    }
    printf("Result = \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
        printf("\n");
    }
}
