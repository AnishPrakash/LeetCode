long long sumAndMultiply(int n) {
    long long x = 0;
    long long sum = 0;
    long long mult = 1;
    
    while (n > 0) {
        int d = n % 10;
        if (d != 0) {
            x = x + d * mult;
            sum = sum + d;
            mult = mult * 10;
        }
        n /= 10;
    }
    
    return x * sum;
}