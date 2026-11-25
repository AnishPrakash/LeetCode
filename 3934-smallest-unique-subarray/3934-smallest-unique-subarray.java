class Solution {
    public int smallestUniqueSubarray(int[] nums) {
        int n = nums.length;
        if (n == 1) {
            return 1;
        }
        int maxVal = 0;
        for (int x : nums) {
            if (x > maxVal) {
                maxVal = x;
            }
        }
        int m = Math.max(n, maxVal) + 1;
        int[] sa = new int[n];
        int[] rank = new int[n];
        int[] tmp = new int[n];
        int[] cnt = new int[m];

        for (int i = 0; i < n; i++) {
            rank[i] = nums[i];
            cnt[rank[i]]++;
        }
        for (int i = 1; i < m; i++) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            sa[--cnt[rank[i]]] = i;
        }

        for (int k = 1; k < n; k <<= 1) {
            int p = 0;
            for (int i = n - k; i < n; i++) {
                tmp[p++] = i;
            }
            for (int i = 0; i < n; i++) {
                if (sa[i] >= k) {
                    tmp[p++] = sa[i] - k;
                }
            }
            Arrays.fill(cnt, 0, m, 0);
            for (int i = 0; i < n; i++) {
                cnt[rank[tmp[i]]]++;
            }
            for (int i = 1; i < m; i++) {
                cnt[i] += cnt[i - 1];
            }
            for (int i = n - 1; i >= 0; i--) {
                sa[--cnt[rank[tmp[i]]]] = tmp[i];
            }
            int[] swap = rank;
            rank = tmp;
            tmp = swap;
            rank[sa[0]] = 1;
            int classes = 1;
            for (int i = 1; i < n; i++) {
                int cur = sa[i];
                int prev = sa[i - 1];
                int cur2 = cur + k < n ? tmp[cur + k] : 0;
                int prev2 = prev + k < n ? tmp[prev + k] : 0;
                if (tmp[cur] != tmp[prev] || cur2 != prev2) {
                    classes++;
                }
                rank[cur] = classes;
            }
            if (classes == n) {
                break;
            }
            m = classes + 1;
        }

        int[] pos = new int[n];
        for (int i = 0; i < n; i++) {
            pos[sa[i]] = i;
        }
        int[] lcp = new int[n];
        int h = 0;
        for (int i = 0; i < n; i++) {
            int r = pos[i];
            if (r == n - 1) {
                h = 0;
                continue;
            }
            int j = sa[r + 1];
            while (i + h < n && j + h < n && nums[i + h] == nums[j + h]) {
                h++;
            }
            lcp[r] = h;
            if (h > 0) {
                h--;
            }
        }

        int ans = n;
        for (int i = 0; i < n; i++) {
            int left = i > 0 ? lcp[i - 1] : 0;
            int right = i < n - 1 ? lcp[i] : 0;
            int need = Math.max(left, right) + 1;
            if (need <= n - sa[i]) {
                ans = Math.min(ans, need);
            }
        }
        return ans;
    }
}