class Solution {
    public List<Integer> busiestServers(int k, int[] arrival, int[] load) {
        int[] count = new int[k];
        
        // TreeSet to store currently available server IDs
        TreeSet<Integer> available = new TreeSet<>();
        for (int i = 0; i < k; i++) {
            available.add(i);
        }
        
        // Min-heap storing [freeTime, serverId]
        PriorityQueue<int[]> busy = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        
        for (int i = 0; i < arrival.length; i++) {
            int curTime = arrival[i];
            int duration = load[i];
            
            // Free all servers that have finished before or at current arrival time
            while (!busy.isEmpty() && busy.peek()[0] <= curTime) {
                available.add(busy.poll()[1]);
            }
            
            // If no servers are available, the request is dropped
            if (available.isEmpty()) {
                continue;
            }
            
            // Search for the smallest server index >= (i % k)
            Integer targetServer = available.ceiling(i % k);
            if (targetServer == null) {
                // Wrap around to the smallest available index
                targetServer = available.first();
            }
            
            // Assign request
            count[targetServer]++;
            available.remove(targetServer);
            busy.offer(new int[]{curTime + duration, targetServer});
        }
        
        // Determine the maximum requests handled
        int maxRequests = 0;
        for (int c : count) {
            maxRequests = Math.max(maxRequests, c);
        }
        
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            if (count[i] == maxRequests) {
                result.add(i);
            }
        }
        
        return result;
    }
}