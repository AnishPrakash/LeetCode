int minInsertions(char* s) {
    int insertions = 0;
    int open_needed = 0;
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] == '(') {
            open_needed++;
            i++;
        } else {
            if (s[i + 1] == ')') {
                i += 2;
            } else {
                insertions++;
                i++;
            }

            if (open_needed > 0) {
                open_needed--;
            } else {
                insertions++;
            }
        }
    }

    insertions += open_needed * 2;
    return insertions;
}