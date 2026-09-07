int distinctSubseqII(char * s) {
    int MOD = 1000000007;
    int last[26] = {0};
    long long total = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        int c = s[i] - 'a';
        long long added = (total + 1 - last[c] + MOD) % MOD;
        total = (total + added) % MOD;
        last[c] = (last[c] + added) % MOD;
    }
    
    return (int)total;
}