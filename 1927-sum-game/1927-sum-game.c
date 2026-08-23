bool sumGame(char * num) {
    int n = strlen(num);
    int sum1 = 0, sum2 = 0;
    int cnt1 = 0, cnt2 = 0;
    
    for(int i = 0; i < n / 2; i++) {
        if(num[i] == '?') cnt1++;
        else sum1 += num[i] - '0';
    }
    
    for(int i = n / 2; i < n; i++) {
        if(num[i] == '?') cnt2++;
        else sum2 += num[i] - '0';
    }
    
    if ((cnt1 + cnt2) % 2 != 0) return true;
    
    return (sum1 - sum2) * 2 != (cnt2 - cnt1) * 9;
}