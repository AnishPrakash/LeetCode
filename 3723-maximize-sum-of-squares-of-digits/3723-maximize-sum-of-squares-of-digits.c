char* maxSumOfSquares(int num, int sum) {
    if (sum > (long long)num * 9) {
        char* empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }
    
    char* res = (char*)malloc(num + 1);
    for (int i = 0; i < num; i++) {
        int d = sum > 9 ? 9 : sum;
        res[i] = d + '0';
        sum -= d;
    }
    res[num] = '\0';
    
    return res;
}