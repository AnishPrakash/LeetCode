int minimumCost(int* nums, int numsSize, int k) {
    long long r = k;
    long long c = 0;
    long long t = 0;
    long long m = 1000000007;
    long long v = 500000004; 
    for (int i = 0; i < numsSize; i++) {
        if (r < nums[i]) {
            long long d = nums[i] - r;
            long long o = (d + k - 1) / k;
            long long x = (c + 1) % m;
            long long y = (c + o) % m;
            long long z = o % m;
            long long b = (((x + y) % m) * z) % m;
            b = (b * v) % m;
            t = (t + b) % m;
            c += o;
            r += o * (long long)k;
        }
        r -= nums[i];
    }
    return (int)t;
}