int findMaxPathScore(int** edges, int edgesSize, int* edgesColSize, bool* online, int onlineSize, long long k) {
    int n = onlineSize;
    int m = edgesSize;
    
    int* head = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        head[i] = -1;
    }
    
    int alloc_size = m > 0 ? m : 1;
    int* to = malloc(alloc_size * sizeof(int));
    int* cost = malloc(alloc_size * sizeof(int));
    int* next = malloc(alloc_size * sizeof(int));
    int* in_degree = calloc(n, sizeof(int));
    
    int max_cost = 0;
    for (int i = 0; i < m; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        to[i] = v;
        cost[i] = w;
        next[i] = head[u];
        head[u] = i;
        in_degree[v]++;
        if (w > max_cost) {
            max_cost = w;
        }
    }
    
    int* topo = malloc(n * sizeof(int));
    int topo_cnt = 0;
    int* q = malloc(n * sizeof(int));
    int head_q = 0, tail_q = 0;
    
    for (int i = 0; i < n; ++i) {
        if (in_degree[i] == 0) {
            q[tail_q++] = i;
        }
    }
    
    while (head_q < tail_q) {
        int u = q[head_q++];
        topo[topo_cnt++] = u;
        for (int e = head[u]; e != -1; e = next[e]) {
            int v = to[e];
            if (--in_degree[v] == 0) {
                q[tail_q++] = v;
            }
        }
    }
    
    long long* dist = malloc(n * sizeof(long long));
    int L = 0, R = max_cost;
    int ans = -1;
    
    while (L <= R) {
        int mid = L + (R - L) / 2;
        
        for (int i = 0; i < n; ++i) {
            dist[i] = LLONG_MAX;
        }
        dist[0] = 0;
        
        for (int i = 0; i < n; ++i) {
            int u = topo[i];
            
            if (dist[u] == LLONG_MAX) continue;
            if (u != 0 && u != n - 1 && !online[u]) continue;
            
            for (int e = head[u]; e != -1; e = next[e]) {
                if (cost[e] < mid) continue;
                
                int v = to[e];
                if (!online[v] && v != n - 1) continue;
                
                if (dist[u] + cost[e] < dist[v]) {
                    dist[v] = dist[u] + cost[e];
                }
            }
        }
        
        if (dist[n - 1] != LLONG_MAX && dist[n - 1] <= k) {
            ans = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    
    free(head);
    free(to);
    free(cost);
    free(next);
    free(in_degree);
    free(topo);
    free(q);
    free(dist);
    
    return ans;
}