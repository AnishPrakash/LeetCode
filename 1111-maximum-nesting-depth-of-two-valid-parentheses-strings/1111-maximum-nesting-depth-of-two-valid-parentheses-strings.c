int* maxDepthAfterSplit(char * seq, int* returnSize) {
    int len = strlen(seq);
    *returnSize = len;
    int* ans = (int*)malloc(len * sizeof(int));
    int d = 0;
    
    for (int i = 0; i < len; i++) {
        if (seq[i] == '(') {
            ans[i] = ++d % 2;
        } else {
            ans[i] = d-- % 2;
        }
    }
    
    return ans;
}