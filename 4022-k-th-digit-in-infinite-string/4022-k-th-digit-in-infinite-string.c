int kthDigit(long long k) {
    if (k<=9){
        return (int)k;
    }
    k-=9;
    long long d = 2;
    long long p10[18];
    p10[0] = 1;
    for (int i = 1; i<=17; i++){
        p10[i] = p10[i-1]*10;
    }
    while(1){
        long long blocks = 9*p10[d-2];
        long long digits = blocks*10*d;
        if (k<=digits){
            break;
        }
        k-=digits;
        d++;
    }
    long long b_start = p10[d-2];
    long long block_offset = (k-1)/(10*d);
    long long b = b_start + block_offset;
    long long rem_k = (k-1)%(10*d);
    long long num_idx = rem_k/d;
    long long digit_idx = rem_k%d;
    long long val;
    if(b%2 == 0){
        val = 10*b+num_idx;
    }
    else{
        val = 10*b+(9-num_idx);
    }
    long long res = (val/p10[d-1-digit_idx])%10;
    return (int)res;
}