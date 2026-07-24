int uniqueXorTriplets(int* nums, int numsSize) {
    bool present[2048] = {false};
    int unique_nums[1505];
    int unique_count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (!present[nums[i]]) {
            present[nums[i]] = true;
            unique_nums[unique_count++] = nums[i];
        }
    }
    
    bool pair_xor[2048] = {false};
    for (int i = 0; i < unique_count; i++) {
        for (int j = i; j < unique_count; j++) {
            pair_xor[unique_nums[i] ^ unique_nums[j]] = true;
        }
    }
    
    bool triplet_xor[2048] = {false};
    int count = 0;
    for (int i = 0; i < 2048; i++) {
        if (pair_xor[i]) {
            for (int j = 0; j < unique_count; j++) {
                int val = i ^ unique_nums[j];
                if (!triplet_xor[val]) {
                    triplet_xor[val] = true;
                    count++;
                }
            }
        }
    }
    
    return count;
}