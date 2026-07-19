char* smallestSubsequence(char* s) {
    int count[26] = {0};
    bool in_stack[26] = {false};
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }
    
    char* stack = (char*)malloc((len + 1) * sizeof(char));
    int top = 0;
    
    for (int i = 0; i < len; i++) {
        int idx = s[i] - 'a';
        count[idx]--;
        
        if (in_stack[idx]) {
            continue;
        }
        
        while (top > 0 && stack[top - 1] > s[i] && count[stack[top - 1] - 'a'] > 0) {
            in_stack[stack[top - 1] - 'a'] = false;
            top--;
        }
        
        stack[top++] = s[i];
        in_stack[idx] = true;
    }
    
    stack[top] = '\0';
    return stack;
}