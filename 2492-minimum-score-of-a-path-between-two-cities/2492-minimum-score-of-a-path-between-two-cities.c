int find(int* parent, int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void union_set(int* parent, int i, int j) {
    int root_i = find(parent, i);
    int root_j = find(parent, j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
    }
}

int minScore(int n, int** roads, int roadsSize, int* roadsColSize) {
    int* parent = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < roadsSize; i++) {
        union_set(parent, roads[i][0], roads[i][1]);
    }
    
    int min_score = 100000; 
    int target_root = find(parent, 1);
    
    for (int i = 0; i < roadsSize; i++) {
        if (find(parent, roads[i][0]) == target_root) {
            if (roads[i][2] < min_score) {
                min_score = roads[i][2];
            }
        }
    }
    
    free(parent);
    return min_score;
}