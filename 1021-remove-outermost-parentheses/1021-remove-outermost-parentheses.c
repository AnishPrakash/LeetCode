char* removeOuterParentheses(char* s) {
    int len = strlen(s);
    char* res = (char*)malloc(sizeof(char) * (len + 1));
    int idx = 0;
    int balance = 0;
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            if (balance > 0) {
                res[idx++] = s[i];
            }
            balance++;
        } else {
            balance--;
            if (balance > 0) {
                res[idx++] = s[i];
            }
        }
    }
    res[idx] = '\0';
    return res;
}