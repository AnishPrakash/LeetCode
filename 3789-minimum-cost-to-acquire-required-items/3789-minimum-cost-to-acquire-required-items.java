class Solution {
    public long minimumCost(long cost1, long cost2, long costBoth, long need1, long need2) {
        if (need1 == 0 && need2 == 0) {
            return 0;
        }

        costBoth = Math.min(costBoth, cost1 + cost2);

        long common = Math.min(need1, need2);
        long extra1 = need1 - common;
        long extra2 = need2 - common;

        long cost = common * costBoth;

        if (extra1 > 0) {
            cost += extra1 * Math.min(cost1, costBoth);
        } else if (extra2 > 0) {
            cost += extra2 * Math.min(cost2, costBoth);
        }

        return cost;
    }
}