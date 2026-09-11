int totalNumbers(int* digits, int digitsSize) {
    int count = 0;
    int freq[10] = {0};
    
    for (int i = 0; i < digitsSize; i++) {
        freq[digits[i]]++;
    }
    
    for (int i = 100; i <= 998; i += 2) {
        int currentFreq[10] = {0};
        currentFreq[i % 10]++;
        currentFreq[(i / 10) % 10]++;
        currentFreq[i / 100]++;
        
        int valid = 1;
        for (int j = 0; j < 10; j++) {
            if (currentFreq[j] > freq[j]) {
                valid = 0;
                break;
            }
        }
        
        if (valid) {
            count++;
        }
    }
    
    return count;
}