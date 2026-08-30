#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int minimumDeletions(int* nums, int numsSize) {
    int min_idx = 0;
    int max_idx = 0;
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < nums[min_idx]) min_idx = i;
        if (nums[i] > nums[max_idx]) max_idx = i;
    }
    
    int i = MIN(min_idx, max_idx);
    int j = MAX(min_idx, max_idx);
    
    int front = j + 1;
    int back = numsSize - i;
    int both = (i + 1) + (numsSize - j);
    
    int res = MIN(front, back);
    return MIN(res, both);
}