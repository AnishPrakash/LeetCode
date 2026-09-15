int maxPalindromes(char* s, int k) {
    int n = strlen(s);
    int ans = 0;
    int last_end = -1;

    for (int center = 0; center < 2 * n - 1; ++center) {
        int l = center / 2;
        int r = l + (center % 2);

        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 >= k) {
                if (l > last_end) {
                    ans++;
                    last_end = r;
                }
                break;
            }
            l--;
            r++;
        }
    }

    return ans;
}