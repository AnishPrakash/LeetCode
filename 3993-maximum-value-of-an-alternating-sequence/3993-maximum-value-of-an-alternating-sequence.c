long long maximumValue(int n, int s, int m) {
    if (n==1){
        return s;
    }
    long long k = n/2;
    long long max = (long long)s+(k*m)-(k-1);
    return max;
}