int min(int a, int b) {
    return a < b ? a : b;
}

int minOperations(int* nums, int numsSize) {
    int n = numsSize;
    if (n <= 1) return 0;

    int pos0 = -1;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            pos0 = i;
            break;
        }
    }

    int inc = 1;
    for (int i = 0; i < n; i++) {
        if (nums[(pos0 + i) % n] != i) {
            inc = 0;
            break;
        }
    }

    int dec = 1;
    for (int i = 0; i < n; i++) {
        if (nums[(pos0 - i + n) % n] != i) {
            dec = 0;
            break;
        }
    }

    if (!inc && !dec) return -1;

    int ans = 2 * n + 5;

    if (inc) {
        int k = pos0;
        ans = min(ans, k);
        ans = min(ans, 1 + (n - k) % n + 1);
    }

    if (dec) {
        int k = (n - 1 - pos0 + n) % n;
        ans = min(ans, 1 + k);
        ans = min(ans, (n - k) % n + 1);
    }

    return ans;
}