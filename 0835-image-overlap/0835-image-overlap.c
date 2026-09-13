int largestOverlap(int** img1, int img1Size, int* img1ColSize, int** img2, int img2Size, int* img2ColSize) {
    int n = img1Size;
    int count[60][60] = {0};
    int p1_r[900], p1_c[900], p1_len = 0;
    int p2_r[900], p2_c[900], p2_len = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(img1[i][j] == 1) {
                p1_r[p1_len] = i;
                p1_c[p1_len] = j;
                p1_len++;
            }
            if(img2[i][j] == 1) {
                p2_r[p2_len] = i;
                p2_c[p2_len] = j;
                p2_len++;
            }
        }
    }
    
    int max_overlap = 0;
    
    for(int i = 0; i < p1_len; i++) {
        for(int j = 0; j < p2_len; j++) {
            int dx = p1_r[i] - p2_r[j] + 30;
            int dy = p1_c[i] - p2_c[j] + 30;
            
            count[dx][dy]++;
            if(count[dx][dy] > max_overlap) {
                max_overlap = count[dx][dy];
            }
        }
    }
    
    return max_overlap;
}