char* rearrangeString(char* s, char x, char y) {
    int low = 0;
    int mid = 0;
    int high = strlen(s)-1;
    while(mid<=high){
        if(s[mid]==y){
            char temp = s[low];
            s[low] = s[mid];
            s[mid] = temp;
            low++;
            mid++;
        }
        else if (s[mid]==x){
            char temp = s[mid];
            s[mid] = s[high];
            s[high] = temp;
            high--;
        }
        else{
            mid++;
        }
    }
    return s;
}