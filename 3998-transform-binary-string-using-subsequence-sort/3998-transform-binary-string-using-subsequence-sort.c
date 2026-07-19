bool* transformStr(char* s, char** strs, int strsSize, int* returnSize) {
    int n = strlen(s);
    *returnSize = strsSize;
    bool* ans = (bool*)malloc(strsSize*sizeof(bool));
    int* p = (int*)malloc(n*sizeof(int));
    int total = 0;
    
    for (int i = 0; i<n; i++){
        if (s[i] == '1'){
            total++;
        }
        p[i] = total;
    }
    
    for (int i = 0; i<strsSize; i++){
        char* str = strs[i];
        int one = 0;
        int t = 0;
        
        for (int j = 0; j<n; j++){
            if(str[j] == '1')
                one++;
            else if (str[j] == '?')
                t++;
        }
        int req = total - one; 
        if (req<0 || req>t){
            ans[i] = false;
            continue;
        }
        int n0 = t - req; 
        int c0 = 0;
        int qs = 0;
        bool valid = true;
        
        for (int j = 0; j<n; j++){ 
            if (str[j] == '1'){
                c0++;
            }
            else if (str[j]=='?'){
                qs++;
                if (qs>n0){
                    c0++;
                }
            }
            if (c0>p[j]){
                valid = false;
                break;
            }
        }
        ans[i] = valid;
    }
    free(p);
    return ans;
}