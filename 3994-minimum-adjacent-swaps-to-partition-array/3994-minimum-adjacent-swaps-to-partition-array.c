int minAdjacentSwaps(int* nums, int numsSize, int a, int b) {
    long long swaps = 0;
    long long c1 = 0;
    long long c2 = 0;
    const int MOD = 1000000007;
    for (int i = 0; i<numsSize; i++){
        if(nums[i]<a){
            swaps = (swaps+c1+c2)%MOD;
        }
        else if (nums[i] <= b){
            swaps = (swaps +c2)%MOD;
            c1++;
        }
        else{
            c2++;
        }
    }
    return (int)swaps;
}