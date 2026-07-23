int uniqueXorTriplets(int* nums, int numsSize) {
    if (numsSize <= 2) {
        return numsSize;
    }
    return 1 << (32 - __builtin_clz(numsSize));
}