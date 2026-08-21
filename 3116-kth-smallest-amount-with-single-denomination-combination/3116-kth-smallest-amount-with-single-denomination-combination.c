long long gcd(long long a, long long b) {
    while (b) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b;
}

long long findKthSmallest(int* coins, int coinsSize, int k) {
    int num_subsets = 1 << coinsSize;
    long long subset_lcm[32768];
    int sign[32768];

    for (int i = 1; i < num_subsets; ++i) {
        long long curr_lcm = 1;
        int bits = 0;
        for (int j = 0; j < coinsSize; ++j) {
            if ((i >> j) & 1) {
                curr_lcm = lcm(curr_lcm, coins[j]);
                bits++;
            }
        }
        subset_lcm[i] = curr_lcm;
        sign[i] = (bits % 2 == 1) ? 1 : -1;
    }

    long long left = 1;
    long long min_c = coins[0];
    for (int i = 1; i < coinsSize; ++i) {
        if (coins[i] < min_c) min_c = coins[i];
    }
    
    long long right = (long long)k * min_c;
    long long ans = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long count = 0;
        
        for (int i = 1; i < num_subsets; ++i) {
            count += sign[i] * (mid / subset_lcm[i]);
        }
        
        if (count >= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}