#define INF 4000000000000000000LL

typedef struct{
    int pos;
    int is_req;
}Point;
int cmp (const void* a, const void* b){
    Point* pa = (Point*)a;
    Point* pb = (Point*)b;
    if (pa->pos < pb->pos) return -1;
    if (pa->pos > pb->pos) return 1;
    return 0;
}
long long elevatorRequests(int n, int start, int* requests, int requestsSize) {
    Point* P = (Point*)malloc((requestsSize+1)*sizeof(Point));
    int sz = 0;
    int start_found = 0;
    for (int i = 0; i<requestsSize; i++){
        P[sz].pos = requests[i];
        P[sz].is_req = 1;
        if(requests[i] == start){
            start_found = 1;
        }
        sz++;
    }
    if(!start_found){
        P[sz].pos = start;
        P[sz].is_req = 0;
        sz++;
    }
    qsort(P,sz,sizeof(Point),cmp);
    int start_idx = -1;
    int* pref = (int*)malloc(sz*sizeof(int));
    for (int i = 0; i<sz; i++){
        if(P[i].pos == start){
            start_idx = i;
        }
        pref[i] = P[i].is_req;
        if(i>0){
            pref[i] += pref[i-1];
        }
    }
    long long* dp = (long long*)malloc((long long)sz*sz*2*sizeof(long long));
    #define DP(i,j,state) dp[((i)*sz+(j))*2+(state)]
    for (int len = sz-1; len>=0; len--){
        for (int i = 0; i+len<sz; i++){
            int j = i+len;
            if (len == sz-1){
                DP(i,j,0) = 0;
                DP(i,j,1) = 0;
                continue;
            }
            int req_in_ij = pref[j] - (i>0 ? pref[i-1]:0);
            long long k = requestsSize - req_in_ij;
            DP(i,j,0) = INF;
            DP(i,j,1) = INF;
            if (i>0){
                long long cost = (long long)(P[i].pos-P[i-1].pos)*k;
                if (DP(i-1,j,0)+cost <DP(i,j,0)) DP(i,j,0) = DP(i-1,j,0)+cost;
            }
            if (j<sz-1){
                long long cost = (long long)(P[j+1].pos-P[i].pos)*k;
                if (DP(i,j+1,1)+cost<DP(i,j,0)) DP(i,j,0) = DP(i,j+1,1)+cost;
            }
            if (i>0){
                long long cost = (long long)(P[j].pos - P[i-1].pos)*k;
                if(DP(i-1,j,0)+cost<DP(i,j,1)) DP(i,j,1) = DP(i-1,j,0)+cost;
            }
            if (j<sz-1){
                long long cost = (long long)(P[j+1].pos - P[j].pos)*k;
                if (DP(i,j+1,1)+cost < DP(i,j,1)) DP(i,j,1) = DP(i,j+1,1)+cost;
            }
        }
    }
    long long ans = DP(start_idx, start_idx, 0);
    free(dp);
    free(pref);
    free(P);
    return ans;
}