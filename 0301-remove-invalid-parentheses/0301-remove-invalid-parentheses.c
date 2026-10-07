void reverse(char* s) {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++; j--;
    }
}

void dfs(char* s, int last_i, int last_j, char p1, char p2, char** res, int* returnSize) {
    int stack = 0;
    int len = strlen(s);
    
    for (int i = last_i; i < len; ++i) {
        if (s[i] == p1) stack++;
        if (s[i] == p2) stack--;
        if (stack >= 0) continue;
        
        for (int j = last_j; j <= i; ++j) {
            if (s[j] == p2 && (j == last_j || s[j - 1] != p2)) {
                char* next = (char*)malloc(len);
                strncpy(next, s, j);
                strcpy(next + j, s + j + 1);
                dfs(next, i, j, p1, p2, res, returnSize);
                free(next);
            }
        }
        return;
    }
    
    char* reversed = (char*)malloc(len + 1);
    strcpy(reversed, s);
    reverse(reversed);
    
    if (p1 == '(') {
        dfs(reversed, 0, 0, ')', '(', res, returnSize);
        free(reversed);
    } else {
        res[*returnSize] = reversed;
        (*returnSize)++;
    }
}

char** removeInvalidParentheses(char* s, int* returnSize) {
    char** res = (char**)malloc(4000 * sizeof(char*));
    *returnSize = 0;
    dfs(s, 0, 0, '(', ')', res, returnSize);
    return res;
}