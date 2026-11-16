class Solution {
    public int numOfSubarrays(int[] arr) {
        int oddCount = 0;
        int evenCount = 1;
        int sum = 0;
        int ans = 0;
        int mod = 1000000007;

        for (int num : arr) {
            sum += num;
            if (sum % 2 == 0) {
                ans = (ans + oddCount) % mod;
                evenCount++;
            } else {
                ans = (ans + evenCount) % mod;
                oddCount++;
            }
        }

        return ans;
    }
}