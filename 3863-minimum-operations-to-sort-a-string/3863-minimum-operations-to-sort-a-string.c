int minOperations(char* s) {
    int n = strlen(s);
    bool sorted = true;
    char min_c = s[0], max_c = s[0];
    
    for (int i = 0; i < n; i++) {
        if (i > 0 && s[i] < s[i - 1]) {
            sorted = false;
        }
        if (s[i] < min_c) min_c = s[i];
        if (s[i] > max_c) max_c = s[i];
    }
    
    if (sorted) return 0;
    if (n == 2) return -1;
    
    if (s[0] == min_c || s[n - 1] == max_c) return 1;
    
    int min_count = 0, max_count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == min_c) min_count++;
        if (s[i] == max_c) max_count++;
    }
    
    if (s[0] == max_c && max_count == 1 && s[n - 1] == min_c && min_count == 1) {
        return 3;
    }
    
    return 2;
}