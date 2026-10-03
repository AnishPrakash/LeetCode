int longestValidParentheses(char* s) {
    int left = 0, right = 0, max_len = 0, len = 0;
    
    for (len = 0; s[len] != '\0'; len++) {
        if (s[len] == '(') {
            left++;
        } else {
            right++;
        }
        
        if (left == right) {
            if (left * 2 > max_len) {
                max_len = left * 2;
            }
        } else if (right > left) {
            left = right = 0;
        }
    }
    
    left = right = 0;
    
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        
        if (left == right) {
            if (left * 2 > max_len) {
                max_len = left * 2;
            }
        } else if (left > right) {
            left = right = 0;
        }
    }
    
    return max_len;
}