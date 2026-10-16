#define MOD 1000000007

long long tree_sq[400005];
long long tree_sum[400005];
long long lazy[400005];

void pushUp(int node) {
    tree_sq[node] = (tree_sq[node * 2] + tree_sq[node * 2 + 1]) % MOD;
    tree_sum[node] = (tree_sum[node * 2] + tree_sum[node * 2 + 1]) % MOD;
}

void apply(int node, int start, int end, long long val) {
    long long len = end - start + 1;
    long long v_mod = val % MOD;
    tree_sq[node] = (tree_sq[node] + 2 * v_mod * tree_sum[node] + len * v_mod % MOD * v_mod) % MOD;
    tree_sum[node] = (tree_sum[node] + len * v_mod) % MOD;
    lazy[node] = (lazy[node] + v_mod) % MOD;
}

void pushDown(int node, int start, int end) {
    if (lazy[node] != 0) {
        int mid = start + (end - start) / 2;
        apply(node * 2, start, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, end, lazy[node]);
        lazy[node] = 0;
    }
}

void update(int node, int start, int end, int l, int r, long long val) {
    if (l <= start && end <= r) {
        apply(node, start, end, val);
        return;
    }
    pushDown(node, start, end);
    int mid = start + (end - start) / 2;
    if (l <= mid) update(node * 2, start, mid, l, r, val);
    if (r > mid) update(node * 2 + 1, mid + 1, end, l, r, val);
    pushUp(node);
}

int sumCounts(int* nums, int numsSize) {
    memset(tree_sq, 0, sizeof(tree_sq));
    memset(tree_sum, 0, sizeof(tree_sum));
    memset(lazy, 0, sizeof(lazy));
    
    int last_pos[100005];
    memset(last_pos, 0, sizeof(last_pos));
    
    long long ans = 0;
    for (int i = 1; i <= numsSize; ++i) {
        int x = nums[i - 1];
        int l = last_pos[x] + 1;
        int r = i;
        
        update(1, 1, numsSize, l, r, 1);
        
        ans = (ans + tree_sq[1]) % MOD;
        last_pos[x] = i;
    }
    
    return ans;
}