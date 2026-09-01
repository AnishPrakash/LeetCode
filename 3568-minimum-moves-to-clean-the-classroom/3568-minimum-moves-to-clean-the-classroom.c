typedef struct {
    int r;
    int c;
    int mask;
    int energy;
    int dist;
} State;

int minMoves(char** classroom, int classroomSize, int energy) {
    int m = classroomSize;
    int n = strlen(classroom[0]);
    int litter_id[20][20];
    memset(litter_id, -1, sizeof(litter_id));

    int k = 0;
    int start_r = -1, start_c = -1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (classroom[i][j] == 'S') {
                start_r = i;
                start_c = j;
            } else if (classroom[i][j] == 'L') {
                litter_id[i][j] = k++;
            }
        }
    }

    if (k == 0) {
        return 0;
    }

    int target_mask = (1 << k) - 1;
    signed char max_e[20][20][1024];
    memset(max_e, -1, sizeof(max_e));

    int cap = 1048576;
    State* q = (State*)malloc(cap * sizeof(State));
    int head = 0, tail = 0;

    q[tail++] = (State){start_r, start_c, 0, energy, 0};
    max_e[start_r][start_c][0] = energy;

    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int ans = -1;

    while (head < tail) {
        State curr = q[head++];

        if (curr.mask == target_mask) {
            ans = curr.dist;
            break;
        }

        if (curr.energy == 0) {
            continue;
        }

        for (int d = 0; d < 4; d++) {
            int nr = curr.r + dirs[d][0];
            int nc = curr.c + dirs[d][1];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                continue;
            }
            if (classroom[nr][nc] == 'X') {
                continue;
            }

            int ne = curr.energy - 1;
            int nmask = curr.mask;

            if (classroom[nr][nc] == 'R') {
                ne = energy;
            } else if (classroom[nr][nc] == 'L') {
                nmask |= (1 << litter_id[nr][nc]);
            }

            if (nmask == target_mask) {
                ans = curr.dist + 1;
                head = tail;
                break;
            }

            if (ne == 0 && classroom[nr][nc] != 'R') {
                continue;
            }

            if (ne <= max_e[nr][nc][nmask]) {
                continue;
            }
            max_e[nr][nc][nmask] = ne;

            if (tail >= cap) {
                cap *= 2;
                q = (State*)realloc(q, cap * sizeof(State));
            }
            q[tail++] = (State){nr, nc, nmask, ne, curr.dist + 1};
        }
    }

    free(q);
    return ans;
}