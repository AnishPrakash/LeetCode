int maximumGap(char* skill, char* station) {
    int n = 0,m=0;
    while(skill[n]!='\0')n++;
    while(station[m]!='\0')m++;
    if (n<=1)return 0;
    int*left = (int*)malloc(n*sizeof(int));
    int j = 0;
    for (int i = 0; i<n; i++){
        while(station[j]!=skill[i]){
            j++;
        }
        left[i] = j;
        j++;
    }
    int max_gap = 0;
    j = m-1;
    for (int i = n-1; i>=1; i--){
        while(station[j]!=skill[i]){
            j--;
        }
        int gap = j-left[i-1];
        if(gap>max_gap){
            max_gap = gap;
        }
        j--;
    }
    free(left);
    return max_gap;
}