struct Node {
    int pre_len;
    int suf_len;
    int max_len;
    char pre_char;
    char suf_char;
    int size;
};

void merge(struct Node* res, struct Node* left, struct Node* right) {
    res->size = left->size + right->size;
    res->pre_char = left->pre_char;
    res->suf_char = right->suf_char;
    
    res->pre_len = left->pre_len;
    if (left->pre_len == left->size && left->pre_char == right->pre_char) {
        res->pre_len += right->pre_len;
    }
    
    res->suf_len = right->suf_len;
    if (right->suf_len == right->size && right->suf_char == left->suf_char) {
        res->suf_len += left->suf_len;
    }
    
    res->max_len = left->max_len > right->max_len ? left->max_len : right->max_len;
    if (left->suf_char == right->pre_char) {
        int combined = left->suf_len + right->pre_len;
        if (combined > res->max_len) {
            res->max_len = combined;
        }
    }
}

void build(struct Node* tree, char* s, int node, int start, int end) {
    if (start == end) {
        tree[node].pre_len = 1;
        tree[node].suf_len = 1;
        tree[node].max_len = 1;
        tree[node].pre_char = s[start];
        tree[node].suf_char = s[start];
        tree[node].size = 1;
        return;
    }
    int mid = start + (end - start) / 2;
    build(tree, s, 2 * node, start, mid);
    build(tree, s, 2 * node + 1, mid + 1, end);
    merge(&tree[node], &tree[2 * node], &tree[2 * node + 1]);
}

void update(struct Node* tree, int node, int start, int end, int idx, char c) {
    if (start == end) {
        tree[node].pre_char = c;
        tree[node].suf_char = c;
        return;
    }
    int mid = start + (end - start) / 2;
    if (idx <= mid) {
        update(tree, 2 * node, start, mid, idx, c);
    } else {
        update(tree, 2 * node + 1, mid + 1, end, idx, c);
    }
    merge(&tree[node], &tree[2 * node], &tree[2 * node + 1]);
}

int* longestRepeating(char * s, char * queryCharacters, int* queryIndices, int queryIndicesSize, int* returnSize) {
    int n = strlen(s);
    struct Node* tree = (struct Node*)malloc(sizeof(struct Node) * 4 * n);
    build(tree, s, 1, 0, n - 1);
    
    int* ans = (int*)malloc(sizeof(int) * queryIndicesSize);
    *returnSize = queryIndicesSize;
    
    for (int i = 0; i < queryIndicesSize; i++) {
        update(tree, 1, 0, n - 1, queryIndices[i], queryCharacters[i]);
        ans[i] = tree[1].max_len;
    }
    
    free(tree);
    return ans;
}