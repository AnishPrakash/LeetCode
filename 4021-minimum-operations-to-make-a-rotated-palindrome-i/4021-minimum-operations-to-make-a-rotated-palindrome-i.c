int minOperations(char* s) {
    int n = strlen(s);
    int min_ops = -1;
    for (int k = 0; k<n; k++){
        int current_ops = k;
        for (int i = 0; i<n/2; i++){
            char left = s[(k+i)%n];
            char right = s[(k+n-1-i)%n];
            int diff = abs(left-right);
            int cost = diff < 26 - diff ? diff:26-diff;
            current_ops += cost;
        }
        if (min_ops == -1 || current_ops < min_ops){
            min_ops = current_ops;
        }
    }
    return min_ops;
}