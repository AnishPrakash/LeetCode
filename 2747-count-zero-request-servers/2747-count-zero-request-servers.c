typedef struct {
    int server_id;
    int time;
} Log;

typedef struct {
    int time;
    int original_index;
} Query;

static int compare_logs(const void *a, const void *b) {
    return ((const Log *)a)->time - ((const Log *)b)->time;
}

static int compare_queries(const void *a, const void *b) {
    return ((const Query *)a)->time - ((const Query *)b)->time;
}

int* countServers(int n, int** logs, int logsSize, int* logsColSize, int x, int* queries, int queriesSize, int* returnSize) {
    *returnSize = queriesSize;
    int* ans = (int*)malloc(sizeof(int) * queriesSize);
    if (!ans) return NULL;

    Log* sorted_logs = (Log*)malloc(sizeof(Log) * logsSize);
    for (int i = 0; i < logsSize; i++) {
        sorted_logs[i].server_id = logs[i][0];
        sorted_logs[i].time = logs[i][1];
    }
    qsort(sorted_logs, logsSize, sizeof(Log), compare_logs);

    Query* sorted_queries = (Query*)malloc(sizeof(Query) * queriesSize);
    for (int i = 0; i < queriesSize; i++) {
        sorted_queries[i].time = queries[i];
        sorted_queries[i].original_index = i;
    }
    qsort(sorted_queries, queriesSize, sizeof(Query), compare_queries);

    int* count = (int*)calloc(n + 1, sizeof(int));
    int active_servers = 0;
    int left = 0;
    int right = 0;

    for (int i = 0; i < queriesSize; i++) {
        int r_time = sorted_queries[i].time;
        int l_time = r_time - x;

        while (right < logsSize && sorted_logs[right].time <= r_time) {
            int sid = sorted_logs[right].server_id;
            if (count[sid] == 0) {
                active_servers++;
            }
            count[sid]++;
            right++;
        }

        while (left < logsSize && sorted_logs[left].time < l_time) {
            int sid = sorted_logs[left].server_id;
            count[sid]--;
            if (count[sid] == 0) {
                active_servers--;
            }
            left++;
        }

        ans[sorted_queries[i].original_index] = n - active_servers;
    }

    free(sorted_logs);
    free(sorted_queries);
    free(count);

    return ans;
}