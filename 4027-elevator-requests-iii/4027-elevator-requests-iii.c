long long elevatorRequests(int n, int start, int** requests, int requestsSize, int* requestsColSize) {
    if (requestsSize == 0) return 0;
    int max_mask = 1 << requestsSize;
    long long* dp = (long long*)malloc((size_t)max_mask * requestsSize * sizeof(long long));
    
    for (int i = 0; i < max_mask * requestsSize; i++) {
        dp[i] = -1;
    }
    for (int i = 0; i < requestsSize; i++) {
        long long diff = (long long)start - requests[i][1];
        long long dist = diff > 0 ? diff : -diff;
        long long arr = requests[i][0];
        dp[(1 << i) * requestsSize + i] = (dist > arr) ? dist : arr;
    }
    
    for (int mask = 1; mask < max_mask; mask++) {
        for (int i = 0; i < requestsSize; i++) {
            if (!(mask & (1 << i))) continue;
            
            long long curr_time = dp[mask * requestsSize + i];
            if (curr_time == -1) continue;
            
            for (int j = 0; j < requestsSize; j++) {
                if (!(mask & (1 << j))) {
                    int next_mask = mask | (1 << j);
                    long long diff = (long long)requests[i][1] - requests[j][1];
                    long long dist = diff > 0 ? diff : -diff;
                    long long arr = requests[j][0];
                    long long time = curr_time + dist;
                    if (time < arr) time = arr;
                    
                    long long current_val = dp[next_mask * requestsSize + j];
                    if (current_val == -1 || time < current_val) {
                        dp[next_mask * requestsSize + j] = time;
                    }
                }
            }
        }
    }
    
    long long min_time = -1;
    int final_mask = max_mask - 1;
    for (int i = 0; i < requestsSize; i++) {
        long long val = dp[final_mask * requestsSize + i];
        if (val != -1) {
            if (min_time == -1 || val < min_time) {
                min_time = val;
            }
        }
    }
    
    free(dp);
    return min_time;
}