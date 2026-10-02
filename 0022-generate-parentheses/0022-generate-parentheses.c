void backtrack(char **result, int *returnSize, char *current, int open, int close, int n, int index) {
    if (open == n && close == n) {
        current[index] = '\0';
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }
    if (open < n) {
        current[index] = '(';
        backtrack(result, returnSize, current, open + 1, close, n, index + 1);
    }
    if (close < open) {
        current[index] = ')';
        backtrack(result, returnSize, current, open, close + 1, n, index + 1);
    }
}

char ** generateParenthesis(int n, int* returnSize) {
    char **result = (char **)malloc(10000 * sizeof(char *));
    char *current = (char *)malloc((2 * n + 1) * sizeof(char));
    *returnSize = 0;
    backtrack(result, returnSize, current, 0, 0, n, 0);
    free(current);
    return result;
}