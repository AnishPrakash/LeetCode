int minMoves(int* nums, int numsSize) {
    int max_val = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > max_val) {
            max_val = nums[i];
        }
    }
    
    int moves = 0;
    for (int i = 0; i < numsSize; i++) {
        moves += max_val - nums[i];
    }
    
    return moves;
}