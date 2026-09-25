#include <stdlib.h>
#include <string.h>

char* my_strdup(const char* s) {
    char* res = malloc(strlen(s) + 1);
    strcpy(res, s);
    return res;
}

int cmp(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

typedef struct {
    char** w;
    int sz;
    int cap;
} Result;

Result make_res() {
    Result r;
    r.sz = 0;
    r.cap = 8;
    r.w = malloc(r.cap * sizeof(char*));
    return r;
}

void add_res(Result* r, char* s) {
    if (r->sz == r->cap) {
        r->cap *= 2;
        r->w = realloc(r->w, r->cap * sizeof(char*));
    }
    r->w[r->sz++] = s;
}

Result merge_union(Result a, Result b) {
    Result r = make_res();
    for(int i = 0; i < a.sz; i++) add_res(&r, my_strdup(a.w[i]));
    for(int i = 0; i < b.sz; i++) add_res(&r, my_strdup(b.w[i]));
    return r;
}

Result merge_concat(Result a, Result b) {
    Result r = make_res();
    for(int i = 0; i < a.sz; i++) {
        for(int j = 0; j < b.sz; j++) {
            char* s = malloc(strlen(a.w[i]) + strlen(b.w[j]) + 1);
            strcpy(s, a.w[i]);
            strcat(s, b.w[j]);
            add_res(&r, s);
        }
    }
    return r;
}

void free_res(Result* r) {
    for(int i = 0; i < r->sz; i++) free(r->w[i]);
    free(r->w);
}

Result parse(char** s) {
    Result cur_union = make_res();
    Result cur_concat = make_res();
    add_res(&cur_concat, my_strdup(""));

    while(**s) {
        if(**s == '{') {
            (*s)++;
            Result r = parse(s);
            Result tmp = merge_concat(cur_concat, r);
            free_res(&cur_concat);
            cur_concat = tmp;
            free_res(&r);
        } else if(**s == '}') {
            (*s)++;
            Result tmp = merge_union(cur_union, cur_concat);
            free_res(&cur_union);
            free_res(&cur_concat);
            return tmp;
        } else if(**s == ',') {
            (*s)++;
            Result tmp = merge_union(cur_union, cur_concat);
            free_res(&cur_union);
            cur_union = tmp;
            free_res(&cur_concat);
            cur_concat = make_res();
            add_res(&cur_concat, my_strdup(""));
        } else {
            char buf[2] = {**s, 0};
            (*s)++;
            Result r = make_res();
            add_res(&r, my_strdup(buf));
            Result tmp = merge_concat(cur_concat, r);
            free_res(&cur_concat);
            cur_concat = tmp;
            free_res(&r);
        }
    }
    Result final_res = merge_union(cur_union, cur_concat);
    free_res(&cur_union);
    free_res(&cur_concat);
    return final_res;
}

char ** braceExpansionII(char * expression, int* returnSize) {
    char* p = expression;
    Result r = parse(&p);
    qsort(r.w, r.sz, sizeof(char*), cmp);
    
    int k = 0;
    for (int i = 0; i < r.sz; i++) {
        if (i == 0 || strcmp(r.w[i], r.w[k-1]) != 0) {
            r.w[k++] = r.w[i];
        } else {
            free(r.w[i]);
        }
    }
    
    *returnSize = k;
    return r.w;
}