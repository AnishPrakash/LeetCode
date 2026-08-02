#include <stdlib.h>

typedef struct{
    int sum;
    int count;
}C;

int cmp_int(const void *a, const void *b){
    int x = *(const int*)a;
    int y = *(const int*)b;
    if(x<y)return -1;
    if(x>y)return 1;
    return 0;
}

int cmp_con(const void* a, const void*b){
    int x = ((const C*)a)->sum;
    int y = ((const C*)b)->sum;
    if(x<y)return -1;
    if(x>y)return 1;
    return 0;
}

int maximumWidth(int* planks, int planksSize) {
    if(planksSize == 0) return 0;
    qsort(planks, planksSize, sizeof(int), cmp_int);
    int U[1005];
    int F[1005];
    int K = 0;
    U[0] = planks[0];
    F[0] = 1;
    K = 1;
    for (int i = 1; i<planksSize; i++){
        if (planks[i] == U[K-1]){
            F[K-1]++;
        }
        else{
            U[K] = planks[i];
            F[K] = 1;
            K++;
        }
    }
    C* c = (C*)malloc(sizeof(C) * 510000);
    int c_size = 0;
    for (int i = 0; i<K; i++){
        c[c_size].sum = U[i];
        c[c_size].count = F[i];
        c_size++;
        for (int j = i; j<K; j++){
            int sum = U[i]+U[j];
            int count;
            if(i == j){
                count = F[i]/2;
            }
            else{
                count = F[i]<F[j]?F[i]:F[j];
            }
            if (count>0){
                c[c_size].sum = sum;
                c[c_size].count = count;
                c_size++;
            }
        }
    }
    qsort(c, c_size, sizeof(C), cmp_con);
    int max_width = 0;
    int current_sum = -1;
    int current_width = 0;
    for (int i = 0; i<c_size; i++){
        if(i==0 || c[i].sum != current_sum){
            if (current_width>max_width){
                max_width = current_width;
            }
            current_sum = c[i].sum;
            current_width = c[i].count;
        }
        else{
            current_width += c[i].count;
        }
    }
    if (current_width>max_width){
        max_width = current_width;
    }
    free(c);
    return max_width;
}