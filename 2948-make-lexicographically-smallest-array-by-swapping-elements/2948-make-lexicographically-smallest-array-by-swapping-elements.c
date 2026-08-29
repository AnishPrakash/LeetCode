typedef struct {
    int val;
    int idx;
} Pair;

int cmpPair(const void* a, const void* b) {
    if (((Pair*)a)->val < ((Pair*)b)->val) return -1;
    if (((Pair*)a)->val > ((Pair*)b)->val) return 1;
    return 0;
}

int cmpInt(const void* a, const void* b) {
    if (*(int*)a < *(int*)b) return -1;
    if (*(int*)a > *(int*)b) return 1;
    return 0;
}

int* lexicographicallySmallestArray(int* nums, int numsSize, int limit, int* returnSize) {
    Pair* pairs = (Pair*)malloc(numsSize * sizeof(Pair));
    for (int i = 0; i < numsSize; i++) {
        pairs[i].val = nums[i];
        pairs[i].idx = i;
    }
    
    qsort(pairs, numsSize, sizeof(Pair), cmpPair);

    int* res = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    int i = 0;
    int* indices = (int*)malloc(numsSize * sizeof(int));
    
    while (i < numsSize) {
        int j = i;
        indices[0] = pairs[i].idx;
        int count = 1;
        
        while (j + 1 < numsSize && pairs[j + 1].val - pairs[j].val <= limit) {
            j++;
            indices[count++] = pairs[j].idx;
        }
        
        qsort(indices, count, sizeof(int), cmpInt);
        
        for (int k = 0; k < count; k++) {
            res[indices[k]] = pairs[i + k].val;
        }
        
        i = j + 1;
    }
    
    free(pairs);
    free(indices);
    return res;
}