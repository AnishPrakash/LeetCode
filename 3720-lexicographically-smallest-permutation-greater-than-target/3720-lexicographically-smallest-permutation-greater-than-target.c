char* lexGreaterPermutation(char* s, char* target) {
    int count[26] = {0};
    int n = strlen(s);
    
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }
    
    int prefix = 0;
    for (int i = 0; i < n; i++) {
        if (count[target[i] - 'a'] > 0) {
            count[target[i] - 'a']--;
            prefix++;
        } else {
            break;
        }
    }
    
    char* res = (char*)malloc(n + 1);
    res[n] = '\0';
    
    for (int i = prefix; i >= 0; i--) {
        if (i < n) {
            int best = -1;
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (count[c] > 0) {
                    best = c;
                    break;
                }
            }
            
            if (best != -1) {
                for (int j = 0; j < i; j++) {
                    res[j] = target[j];
                }
                res[i] = best + 'a';
                count[best]--;
                
                int idx = i + 1;
                for (int c = 0; c < 26; c++) {
                    while (count[c] > 0) {
                        res[idx++] = c + 'a';
                        count[c]--;
                    }
                }
                return res;
            }
        }
        if (i > 0) {
            count[target[i - 1] - 'a']++;
        }
    }
    
    res[0] = '\0';
    return res;
}