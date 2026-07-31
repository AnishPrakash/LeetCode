int minimumPushes(char* word) {
    int freq[26] = {0};
    
    for (int i = 0; word[i] != '\0'; i++) {
        freq[word[i] - 'a']++;
    }
    
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (freq[i] < freq[j]) {
                int temp = freq[i];
                freq[i] = freq[j];
                freq[j] = temp;
            }
        }
    }
    
    int total = 0;
    for (int i = 0; i < 26 && freq[i] > 0; i++) {
        total += freq[i] * ((i / 8) + 1);
    }
    
    return total;
}