typedef struct {
    int remain[6];
    int prod;
} Node;

Node merge(Node left, Node right, int k) {
    Node node;
    memset(node.remain, 0, sizeof(node.remain));
    node.prod = (left.prod * right.prod) % k;
    for (int i = 0; i < k; ++i) {
        node.remain[i] = left.remain[i];
    }
    for (int i = 0; i < k; ++i) {
        node.remain[(left.prod * i) % k] += right.remain[i];
    }
    return node;
}

void build(Node* tree, int* nums, int cur, int left, int right, int k) {
    if (left == right) {
        memset(tree[cur].remain, 0, sizeof(tree[cur].remain));
        int val = nums[left] % k;
        tree[cur].remain[val] = 1;
        tree[cur].prod = val;
        return;
    }
    int mid = (left + right) / 2;
    build(tree, nums, 2 * cur + 1, left, mid, k);
    build(tree, nums, 2 * cur + 2, mid + 1, right, k);
    tree[cur] = merge(tree[2 * cur + 1], tree[2 * cur + 2], k);
}

void update(Node* tree, int cur, int left, int right, int idx, int val, int k) {
    if (left == right) {
        memset(tree[cur].remain, 0, sizeof(tree[cur].remain));
        tree[cur].remain[val] = 1;
        tree[cur].prod = val;
        return;
    }
    int mid = (left + right) / 2;
    if (idx <= mid) {
        update(tree, 2 * cur + 1, left, mid, idx, val, k);
    } else {
        update(tree, 2 * cur + 2, mid + 1, right, idx, val, k);
    }
    tree[cur] = merge(tree[2 * cur + 1], tree[2 * cur + 2], k);
}

Node query(Node* tree, int cur, int left, int right, int ql, int qr, int k) {
    if (ql <= left && right <= qr) {
        return tree[cur];
    }
    int mid = (left + right) / 2;
    if (qr <= mid) {
        return query(tree, 2 * cur + 1, left, mid, ql, qr, k);
    }
    if (ql > mid) {
        return query(tree, 2 * cur + 2, mid + 1, right, ql, qr, k);
    }
    Node l_node = query(tree, 2 * cur + 1, left, mid, ql, qr, k);
    Node r_node = query(tree, 2 * cur + 2, mid + 1, right, ql, qr, k);
    return merge(l_node, r_node, k);
}

int* resultArray(int* nums, int numsSize, int k, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    Node* tree = (Node*)malloc(sizeof(Node) * 4 * numsSize);
    build(tree, nums, 0, 0, numsSize - 1, k);
    
    int* ans = (int*)malloc(sizeof(int) * queriesSize);
    *returnSize = queriesSize;
    
    for (int i = 0; i < queriesSize; i++) {
        int index = queries[i][0];
        int value = queries[i][1] % k;
        int start = queries[i][2];
        int x = queries[i][3];
        
        update(tree, 0, 0, numsSize - 1, index, value, k);
        Node res = query(tree, 0, 0, numsSize - 1, start, numsSize - 1, k);
        ans[i] = res.remain[x];
    }
    
    free(tree);
    return ans;
}