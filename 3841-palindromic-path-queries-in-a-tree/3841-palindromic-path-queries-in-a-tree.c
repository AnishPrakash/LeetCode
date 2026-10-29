#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int* head_edge;
int* to_edge;
int* next_edge;
int edge_cnt;

void add_edge(int u, int v) {
    to_edge[edge_cnt] = v;
    next_edge[edge_cnt] = head_edge[u];
    head_edge[u] = edge_cnt++;
}

int* parent;
int* depth;
int* heavy;
int* sz;
int* head;
int* pos;
int current_pos;

int dfs1(int v, int p, int d) {
    sz[v] = 1;
    parent[v] = p;
    depth[v] = d;
    heavy[v] = -1;
    int max_sub = 0;
    for (int i = head_edge[v]; i != -1; i = next_edge[i]) {
        int to = to_edge[i];
        if (to != p) {
            int sub_sz = dfs1(to, v, d + 1);
            sz[v] += sub_sz;
            if (sub_sz > max_sub) {
                max_sub = sub_sz;
                heavy[v] = to;
            }
        }
    }
    return sz[v];
}

void dfs2(int v, int p, int h) {
    head[v] = h;
    pos[v] = ++current_pos;
    if (heavy[v] != -1) {
        dfs2(heavy[v], v, h);
    }
    for (int i = head_edge[v]; i != -1; i = next_edge[i]) {
        int to = to_edge[i];
        if (to != p && to != heavy[v]) {
            dfs2(to, v, to);
        }
    }
}

int* bit;
int bit_n;

void bit_update(int idx, int val) {
    for (; idx <= bit_n; idx += idx & -idx) {
        bit[idx] ^= val;
    }
}

int bit_query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum ^= bit[idx];
    }
    return sum;
}

int query_range(int l, int r) {
    return bit_query(r) ^ bit_query(l - 1);
}

int query_path(int u, int v) {
    int res = 0;
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]]) {
            int temp = u; u = v; v = temp;
        }
        res ^= query_range(pos[head[u]], pos[u]);
        u = parent[head[u]];
    }
    if (depth[u] > depth[v]) {
        int temp = u; u = v; v = temp;
    }
    res ^= query_range(pos[u], pos[v]);
    return res;
}

bool* palindromePath(int n, int** edges, int edgesSize, int* edgesColSize, char * s, char ** queries, int queriesSize, int* returnSize) {
    head_edge = (int*)malloc(n * sizeof(int));
    to_edge = (int*)malloc(2 * n * sizeof(int));
    next_edge = (int*)malloc(2 * n * sizeof(int));
    for (int i = 0; i < n; i++) head_edge[i] = -1;
    edge_cnt = 0;

    for (int i = 0; i < edgesSize; i++) {
        add_edge(edges[i][0], edges[i][1]);
        add_edge(edges[i][1], edges[i][0]);
    }

    parent = (int*)malloc(n * sizeof(int));
    depth = (int*)malloc(n * sizeof(int));
    heavy = (int*)malloc(n * sizeof(int));
    sz = (int*)malloc(n * sizeof(int));
    head = (int*)malloc(n * sizeof(int));
    pos = (int*)malloc(n * sizeof(int));
    current_pos = 0;

    dfs1(0, -1, 0);
    dfs2(0, -1, 0);

    bit_n = n;
    bit = (int*)calloc((n + 1), sizeof(int));

    int* current_mask = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        current_mask[i] = 1 << (s[i] - 'a');
        bit_update(pos[i], current_mask[i]);
    }

    int q_count = 0;
    for (int i = 0; i < queriesSize; i++) {
        if (queries[i][0] == 'q') q_count++;
    }

    bool* ans = (bool*)malloc(q_count * sizeof(bool));
    *returnSize = q_count;
    int ans_idx = 0;

    for (int i = 0; i < queriesSize; i++) {
        if (queries[i][0] == 'u') {
            int u;
            char c;
            sscanf(queries[i], "update %d %c", &u, &c);
            int new_m = 1 << (c - 'a');
            bit_update(pos[u], current_mask[u] ^ new_m);
            current_mask[u] = new_m;
        } else {
            int u, v;
            sscanf(queries[i], "query %d %d", &u, &v);
            int mask = query_path(u, v);
            ans[ans_idx++] = (mask & (mask - 1)) == 0;
        }
    }

    free(head_edge); 
    free(to_edge); 
    free(next_edge);
    free(parent); 
    free(depth); 
    free(heavy); 
    free(sz);
    free(head); 
    free(pos); 
    free(bit); 
    free(current_mask);

    return ans;
}