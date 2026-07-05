int* pathsWithMaxScore(char ** board, int boardSize, int* returnSize) {
    int n = boardSize;
    *returnSize = 2;
    int* res = (int*)malloc(2 * sizeof(int));
    res[0] = 0; 
    res[1] = 0;

    int score[105][105];
    int paths[105][105];
    int mod = 1000000007;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            score[i][j] = -1;
            paths[i][j] = 0;
        }
    }

    score[n - 1][n - 1] = 0;
    paths[n - 1][n - 1] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (board[i][j] == 'X' || (i == n - 1 && j == n - 1)) {
                continue;
            }

            int max_s = -1;
            
            if (i + 1 < n && score[i + 1][j] != -1) {
                max_s = score[i + 1][j];
            }
            if (j + 1 < n && score[i][j + 1] != -1 && score[i][j + 1] > max_s) {
                max_s = score[i][j + 1];
            }
            if (i + 1 < n && j + 1 < n && score[i + 1][j + 1] != -1 && score[i + 1][j + 1] > max_s) {
                max_s = score[i + 1][j + 1];
            }

            if (max_s == -1) {
                continue;
            }

            int p = 0;
            
            if (i + 1 < n && score[i + 1][j] == max_s) {
                p = (p + paths[i + 1][j]) % mod;
            }
            if (j + 1 < n && score[i][j + 1] == max_s) {
                p = (p + paths[i][j + 1]) % mod;
            }
            if (i + 1 < n && j + 1 < n && score[i + 1][j + 1] == max_s) {
                p = (p + paths[i + 1][j + 1]) % mod;
            }

            int val = 0;
            if (board[i][j] != 'E' && board[i][j] != 'S') {
                val = board[i][j] - '0';
            }

            score[i][j] = max_s + val;
            paths[i][j] = p;
        }
    }

    if (score[0][0] != -1) {
        res[0] = score[0][0];
        res[1] = paths[0][0];
    }

    return res;
}