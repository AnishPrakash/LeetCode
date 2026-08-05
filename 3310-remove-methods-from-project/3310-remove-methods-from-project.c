int* remainingMethods(int n, int k, int** invocations, int invocationsSize, int* invocationsColSize, int* returnSize) {
    int* head = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        head[i] = -1;
    }

    int* next = (int*)malloc(invocationsSize * sizeof(int));
    int* to = (int*)malloc(invocationsSize * sizeof(int));

    for (int i = 0; i < invocationsSize; i++) {
        int u = invocations[i][0];
        int v = invocations[i][1];
        to[i] = v;
        next[i] = head[u];
        head[u] = i;
    }

    bool* suspicious = (bool*)calloc(n, sizeof(bool));
    int* q = (int*)malloc(n * sizeof(int));
    int head_q = 0, tail_q = 0;

    q[tail_q++] = k;
    suspicious[k] = true;

    while (head_q < tail_q) {
        int u = q[head_q++];
        for (int i = head[u]; i != -1; i = next[i]) {
            int v = to[i];
            if (!suspicious[v]) {
                suspicious[v] = true;
                q[tail_q++] = v;
            }
        }
    }

    bool can_remove = true;
    for (int i = 0; i < invocationsSize; i++) {
        if (!suspicious[invocations[i][0]] && suspicious[invocations[i][1]]) {
            can_remove = false;
            break;
        }
    }

    int* res = (int*)malloc(n * sizeof(int));
    int res_size = 0;

    if (!can_remove) {
        for (int i = 0; i < n; i++) {
            res[res_size++] = i;
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                res[res_size++] = i;
            }
        }
    }

    *returnSize = res_size;

    free(head);
    free(next);
    free(to);
    free(suspicious);
    free(q);

    return res;
}