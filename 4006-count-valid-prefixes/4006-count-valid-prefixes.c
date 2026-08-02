int countValidPrefixes(char* s) {
    int c0 = 0;
    int c1 = 0;
    int ans = 0;
    for (int i = 0; s[i]!='\0'; i++){
        if(s[i] == '0'){
            c0++;
        }
        else{
            c1++;
        }
        int diff = c0-c1;
        if(diff == 0 || diff == 1 || diff == -1){
            ans++;
        }
    }
    return ans;
}