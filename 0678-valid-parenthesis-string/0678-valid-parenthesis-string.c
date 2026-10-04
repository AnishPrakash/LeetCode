bool checkValidString(char * s) {
    int cmin = 0, cmax = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            cmin++;
            cmax++;
        } else if (s[i] == ')') {
            cmin--;
            cmax--;
        } else {
            cmin--;
            cmax++;
        }
        
        if (cmax < 0) {
            return false;
        }
        if (cmin < 0) {
            cmin = 0;
        }
    }
    
    return cmin == 0;
}