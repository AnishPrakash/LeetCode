void dfs(int u, int n, int adj[][50], int degree[], int visited[], int* v_count, int* e_count) {
    visited[u] = 1;
    (*v_count)++;
    (*e_count) += degree[u];
    for (int i = 0; i < n; i++) {
        if (adj[u][i] && !visited[i]) {
            dfs(i, n, adj, degree, visited, v_count, e_count);
        }
    }
}

int countCompleteComponents(int n, int** edges, int edgesSize, int* edgesColSize) {
    int adj[50][50] = {0};
    int degree[50] = {0};
    int visited[50] = {0};
    int count = 0;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][v] = 1;
        adj[v][u] = 1;
        degree[u]++;
        degree[v]++;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int v_count = 0;
            int e_count = 0;
            dfs(i, n, adj, degree, visited, &v_count, &e_count);
            if (e_count == v_count * (v_count - 1)) {
                count++;
            }
        }
    }

    return count;
}