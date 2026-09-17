int minSumOfLengths(int* arr, int arrSize, int target) {
    int* min_len = (int*)malloc(arrSize * sizeof(int));
    int left = 0;
    int sum = 0;
    int ans = 1000000000;
    int best_so_far = 1000000000;

    for (int right = 0; right < arrSize; ++right) {
        sum += arr[right];
        
        while (sum > target && left <= right) {
            sum -= arr[left++];
        }
        
        if (sum == target) {
            int current_len = right - left + 1;
            
            if (left > 0 && min_len[left - 1] != 1000000000) {
                if (min_len[left - 1] + current_len < ans) {
                    ans = min_len[left - 1] + current_len;
                }
            }
            if (current_len < best_so_far) {
                best_so_far = current_len;
            }
        }
        min_len[right] = best_so_far;
    }

    free(min_len);
    return ans == 1000000000 ? -1 : ans;
}