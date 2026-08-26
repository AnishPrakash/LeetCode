char* shortestBeautifulSubstring(char* s, int k) {
    int n = strlen(s);
    int min_len = n + 1;
    int best_start = -1;

    for (int i = 0; i < n; i++) {
        int ones = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == '1') {
                ones++;
            }
            if (ones == k) {
                int len = j - i + 1;
                if (len < min_len) {
                    min_len = len;
                    best_start = i;
                } else if (len == min_len) {
                    if (best_start == -1 || strncmp(s + i, s + best_start, len) < 0) {
                        best_start = i;
                    }
                }
            } else if (ones > k) {
                break;
            }
        }
    }

    if (best_start == -1) {
        char* res = (char*)malloc(1);
        res[0] = '\0';
        return res;
    }

    char* res = (char*)malloc(min_len + 1);
    strncpy(res, s + best_start, min_len);
    res[min_len] = '\0';
    return res;
}