int compare(const void *a, const void *b) {
    int *intervalA = *(int **)a;
    int *intervalB = *(int **)b;
    
    if (intervalA[0] == intervalB[0]) {
        return intervalB[1] - intervalA[1];
    }
    return intervalA[0] - intervalB[0];
}

int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) {
        return 0;
    }
    
    qsort(intervals, intervalsSize, sizeof(int*), compare);
    
    int count = 0;
    int max_end = -1;
    
    for (int i = 0; i < intervalsSize; i++) {
        if (intervals[i][1] > max_end) {
            count++;
            max_end = intervals[i][1];
        }
    }
    
    return count;
}