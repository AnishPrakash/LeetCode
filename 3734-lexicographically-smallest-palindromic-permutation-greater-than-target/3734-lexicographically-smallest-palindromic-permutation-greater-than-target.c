char* lexPalindromicPermutation(char* s, char* target) {
    int n = strlen(s);
    int counts[26] = {0};
    
    for (int i = 0; i < n; i++) {
        counts[s[i] - 'a']++;
    }
    
    int oddCount = 0;
    char midChar = 0;
    for (int i = 0; i < 26; i++) {
        if (counts[i] % 2 != 0) {
            oddCount++;
            midChar = i + 'a';
        }
    }
    
    char* emptyRes = (char*)malloc(1);
    emptyRes[0] = '\0';
    
    if (oddCount > 1) {
        return emptyRes;
    }
    
    int half[26];
    for (int i = 0; i < 26; i++) {
        half[i] = counts[i] / 2;
    }
    
    int L = n / 2;
    char* res = (char*)malloc(n + 1);
    res[n] = '\0';
    
    for (int k = L; k >= 0; k--) {
        int currHalf[26];
        memcpy(currHalf, half, sizeof(half));
        
        bool canFormPrefix = true;
        for (int i = 0; i < k; i++) {
            int c = target[i] - 'a';
            if (currHalf[c] > 0) {
                currHalf[c]--;
            } else {
                canFormPrefix = false;
                break;
            }
        }
        
        if (!canFormPrefix) continue;
        
        if (k == L) {
            for (int i = 0; i < L; i++) res[i] = target[i];
            if (n % 2 != 0) res[L] = midChar;
            for (int i = 0; i < L; i++) res[n - 1 - i] = res[i];
            
            if (strcmp(res, target) > 0) {
                free(emptyRes);
                return res;
            }
        } else {
            int nextChar = -1;
            for (int c = target[k] - 'a' + 1; c < 26; c++) {
                if (currHalf[c] > 0) {
                    nextChar = c;
                    break;
                }
            }
            
            if (nextChar != -1) {
                for (int i = 0; i < k; i++) res[i] = target[i];
                res[k] = nextChar + 'a';
                currHalf[nextChar]--;
                
                int idx = k + 1;
                for (int c = 0; c < 26; c++) {
                    while (currHalf[c] > 0) {
                        res[idx++] = c + 'a';
                        currHalf[c]--;
                    }
                }
                
                if (n % 2 != 0) res[L] = midChar;
                for (int i = 0; i < L; i++) res[n - 1 - i] = res[i];
                
                free(emptyRes);
                return res;
            }
        }
    }
    
    free(res);
    return emptyRes;
}