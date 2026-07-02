bool findSafeWalk(int** grid, int gridSize, int* gridColSize, int health) {
    int m = gridSize;
    int n = gridColSize[0];
    int min_cost[50][50];
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            min_cost[i][j] = INT_MAX;
        }
    }
    
    typedef struct {
        int r, c, cost;
    } Node;
    
    Node* q = (Node*)malloc(sizeof(Node) * 20000);
    int head = 10000;
    int tail = 10000;
    
    int start_cost = grid[0][0];
    min_cost[0][0] = start_cost;
    
    q[tail].r = 0;
    q[tail].c = 0;
    q[tail].cost = start_cost;
    tail++;
    
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    
    while (head < tail) {
        Node curr = q[head++];
        int r = curr.r;
        int c = curr.c;
        int cost = curr.cost;
        
        if (cost > min_cost[r][c]) {
            continue;
        }
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                int new_cost = cost + grid[nr][nc];
                
                if (new_cost < min_cost[nr][nc]) {
                    min_cost[nr][nc] = new_cost;
                    
                    if (grid[nr][nc] == 0) {
                        head--;
                        q[head].r = nr;
                        q[head].c = nc;
                        q[head].cost = new_cost;
                    } else {
                        q[tail].r = nr;
                        q[tail].c = nc;
                        q[tail].cost = new_cost;
                        tail++;
                    }
                }
            }
        }
    }
    
    bool result = (health - min_cost[m - 1][n - 1] >= 1);
    free(q);
    return result;
}