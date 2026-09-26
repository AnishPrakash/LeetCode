int cmp(const void* a, const void* b) {
    char** pa = *(char***)a;
    char** pb = *(char***)b;
    return strcmp(pa[0], pb[0]);
}

char* evaluate(char* s, char*** knowledge, int knowledgeSize, int* knowledgeColSize) {
    qsort(knowledge, knowledgeSize, sizeof(char**), cmp);
    int n = strlen(s);
    char* ans = (char*)malloc(n * 11 + 1);
    int idx = 0;
    int i = 0;
    char key[15];
    
    while (i < n) {
        if (s[i] == '(') {
            i++;
            int k = 0;
            while (s[i] != ')') {
                key[k++] = s[i++];
            }
            key[k] = '\0';
            i++;
            
            int l = 0, r = knowledgeSize - 1;
            char* val = "?";
            while (l <= r) {
                int mid = l + (r - l) / 2;
                int c = strcmp(knowledge[mid][0], key);
                if (c == 0) {
                    val = knowledge[mid][1];
                    break;
                } else if (c < 0) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            
            while (*val) {
                ans[idx++] = *val++;
            }
        } else {
            ans[idx++] = s[i++];
        }
    }
    
    ans[idx] = '\0';
    return ans;
}