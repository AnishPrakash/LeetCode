int countCommas(int n) {
    int count = 0;
    if (n >= 1000) count += n - 999;
    if (n >= 1000000) count += n - 999999;
    if (n >= 1000000000) count += n - 999999999;
    return count;
}