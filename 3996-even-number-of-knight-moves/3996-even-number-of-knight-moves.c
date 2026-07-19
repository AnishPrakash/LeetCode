bool canReach(int* start, int startSize, int* target, int targetSize) {
    int s = (start[0]+start[1])%2;
    int t = (target[0]+target[1])%2;
    return s == t;
}