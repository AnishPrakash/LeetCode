char* smallestPalindrome(char* s) {
    int count[26] = {0};
    int n = 0;
    
    for (int i = 0; s[i]; i++) {
        count[s[i] - 'a']++;
        n++;
    }
    
    int left = 0;
    int right = n - 1;
    
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 != 0) {
            s[n / 2] = i + 'a';
            count[i]--;
        }
        while (count[i] > 0) {
            s[left++] = i + 'a';
            s[right--] = i + 'a';
            count[i] -= 2;
        }
    }
    
    return s;
}