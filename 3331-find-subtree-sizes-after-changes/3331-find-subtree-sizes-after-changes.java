class Solution {
    private List<Integer>[] adj;
    private List<Integer>[] newAdj;
    private int[] lastSeen;
    private int[] newParent;
    private int[] ans;
    private String s;

    public int[] findSubtreeSizes(int[] parent, String s) {
        int n = parent.length;
        this.s = s;
        adj = new ArrayList[n];
        newAdj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
            newAdj[i] = new ArrayList<>();
        }
        for (int i = 1; i < n; i++) {
            adj[parent[i]].add(i);
        }

        newParent = Arrays.copyOf(parent, n);
        lastSeen = new int[26];
        Arrays.fill(lastSeen, -1);

        dfsFindParents(0);

        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].add(i);
        }

        ans = new int[n];
        dfsCountSizes(0);

        return ans;
    }

    private void dfsFindParents(int u) {
        int charIdx = s.charAt(u) - 'a';
        int prev = lastSeen[charIdx];
        if (u != 0 && prev != -1) {
            newParent[u] = prev;
        }
        lastSeen[charIdx] = u;
        for (int v : adj[u]) {
            dfsFindParents(v);
        }
        lastSeen[charIdx] = prev;
    }

    private int dfsCountSizes(int u) {
        int size = 1;
        for (int v : newAdj[u]) {
            size += dfsCountSizes(v);
        }
        ans[u] = size;
        return size;
    }
}