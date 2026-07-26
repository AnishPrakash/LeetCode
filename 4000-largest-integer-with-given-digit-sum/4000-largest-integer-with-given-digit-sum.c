int largestInteger(int n, int s) {
    if(s>n*9){
        return -1;
    }
    int result = 0;
    for (int i = 0; i<n; i++){
        int d = s>9?9:s;
        result = result*10+d;
        s-=d;
    }
    return result;
}