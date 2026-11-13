class Solution {
    public long countNonDecreasingSubarrays(int[] nums, int k) {
        int n = nums.length;
        long ans = 0;
        long cost = 0;
        Deque<int[]> dq = new ArrayDeque<>();
        int r = n - 1;

        for (int l = n - 1; l >= 0; l--) {
            int val = nums[l];
            int count = 1;

            while (!dq.isEmpty() && dq.peekFirst()[0] < val) {
                int[] block = dq.pollFirst();
                cost += (long) (val - block[0]) * block[1];
                count += block[1];
            }
            dq.offerFirst(new int[]{val, count});

            while (cost > k) {
                int[] last = dq.peekLast();
                cost -= (long) (last[0] - nums[r]);
                last[1]--;
                if (last[1] == 0) {
                    dq.pollLast();
                }
                r--;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
}