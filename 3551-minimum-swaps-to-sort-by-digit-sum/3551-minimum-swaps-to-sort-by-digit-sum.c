typedef struct {
    int val;
    int sum;
    int idx;
} Element;

int getDigitSum(int n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int cmp(const void* a, const void* b) {
    Element* ea = (Element*)a;
    Element* eb = (Element*)b;
    if (ea->sum != eb->sum) {
        return ea->sum - eb->sum;
    }
    if (ea->val < eb->val) return -1;
    if (ea->val > eb->val) return 1;
    return 0;
}

int minSwaps(int* nums, int numsSize) {
    Element* arr = (Element*)malloc(numsSize * sizeof(Element));
    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].sum = getDigitSum(nums[i]);
        arr[i].idx = i;
    }
    
    qsort(arr, numsSize, sizeof(Element), cmp);
    
    int swaps = 0;
    int* visited = (int*)calloc(numsSize, sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        if (visited[i] || arr[i].idx == i) {
            continue;
        }
        int cycle_size = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = 1;
            j = arr[j].idx;
            cycle_size++;
        }
        if (cycle_size > 0) {
            swaps += (cycle_size - 1);
        }
    }
    
    free(visited);
    free(arr);
    return swaps;
}