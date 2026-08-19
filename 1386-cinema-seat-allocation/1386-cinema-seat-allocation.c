int cmp(const void *a, const void *b) {
    int *pa = *(int **)a;
    int *pb = *(int **)b;
    if (pa[0] != pb[0]) return pa[0] - pb[0];
    return pa[1] - pb[1];
}

int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize) {
    qsort(reservedSeats, reservedSeatsSize, sizeof(int*), cmp);
    
    int ans = 2 * n;
    int i = 0;
    
    while (i < reservedSeatsSize) {
        int currentRow = reservedSeats[i][0];
        int mask = 0;
        
        while (i < reservedSeatsSize && reservedSeats[i][0] == currentRow) {
            int seat = reservedSeats[i][1];
            if (seat >= 2 && seat <= 9) {
                mask |= (1 << (seat - 2));
            }
            i++;
        }
        
        ans -= 2;
        if ((mask & 0x0F) == 0 && (mask & 0xF0) == 0) {
            ans += 2;
        } else if ((mask & 0x0F) == 0 || (mask & 0xF0) == 0 || (mask & 0x3C) == 0) {
            ans += 1;
        }
    }
    
    return ans;
}