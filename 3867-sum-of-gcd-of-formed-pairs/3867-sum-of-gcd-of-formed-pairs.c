#include <stdlib.h>

int gcd(int a, int b) {
    while (b) {
        a %= b;
        int t = a;
        a = b;
        b = t;
    }
    return a;
}

int compare(const void* a, const void* b) {
    int v1 = *(const int*)a;
    int v2 = *(const int*)b;
    return (v1 > v2) - (v1 < v2);
}

long long gcdSum(int* nums, int numsSize) {
    int* p = (int*)malloc(numsSize * sizeof(int));
    int m = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > m) m = nums[i];
        p[i] = gcd(nums[i], m);
    }
    qsort(p, numsSize, sizeof(int), compare);
    long long s = 0;
    int l = 0, r = numsSize - 1;
    while (l < r) {
        s += gcd(p[l], p[r]);
        l++;
        r--;
    }
    free(p);
    return s;
}