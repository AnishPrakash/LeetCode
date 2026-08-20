int* resultArray(int* nums, int numsSize, int* returnSize) {
    int* arr1 = (int*)malloc(numsSize * sizeof(int));
    int* arr2 = (int*)malloc(numsSize * sizeof(int));
    int count1 = 0, count2 = 0;
    
    arr1[count1++] = nums[0];
    arr2[count2++] = nums[1];
    
    for (int i = 2; i < numsSize; i++) {
        if (arr1[count1 - 1] > arr2[count2 - 1]) {
            arr1[count1++] = nums[i];
        } else {
            arr2[count2++] = nums[i];
        }
    }
    
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    for (int i = 0; i < count1; i++) {
        result[i] = arr1[i];
    }
    for (int i = 0; i < count2; i++) {
        result[count1 + i] = arr2[i];
    }
    
    free(arr1);
    free(arr2);
    
    return result;
}