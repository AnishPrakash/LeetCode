class Solution {
    public int maximumSaleItems(int[][] items, int budget) {
        int maxFactor = 0;
        int cheapest = Integer.MAX_VALUE;
        for (int[] item : items) {
            if (item[0] > maxFactor) {
                maxFactor = item[0];
            }
            if (item[1] < cheapest) {
                cheapest = item[1];
            }
        }

        int[] multiples = new int[maxFactor + 1];
        for (int[] item : items) {
            multiples[item[0]]++;
        }

        for (int i = 1; i <= maxFactor; i++) {
            if (multiples[i] > 0) {
                for (int m = 2 * i; m <= maxFactor; m += i) {
                    multiples[i] += multiples[m];
                }
            }
        }

        Arrays.sort(items, Comparator.comparingInt(a -> a[1]));

        long remaining = budget;
        long total = 0;
        long limit = 2L * cheapest;

        for (int[] item : items) {
            int price = item[1];
            if (price >= limit || remaining < price) {
                break;
            }
            int freeCopies = multiples[item[0]] - 1;
            if (freeCopies > 0) {
                long take = Math.min(freeCopies, remaining / price);
                total += 2 * take;
                remaining -= take * price;
            }
        }

        total += remaining / cheapest;
        return (int) total;
    }
}