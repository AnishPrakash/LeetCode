long long countCommas(long long n) {
    long long commas = 0;
    long long base = 1000;
    
    while (n >= base) {
        commas += (n - base + 1);
        if (base > 1000000000000000LL) {
            break;
        }
        base *= 1000;
    }
    
    return commas;
}