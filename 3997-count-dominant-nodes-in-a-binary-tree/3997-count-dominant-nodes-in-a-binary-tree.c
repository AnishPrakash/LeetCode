int dfs (struct TreeNode* node, int* count){
    if(node==NULL){
        return 0;
    }
    int l = dfs(node->left, count);
    int r = dfs(node->right, count);
    int max = (l>r)?l:r;
    if(node->val >= max){
        (*count)++;
        return node->val;
    }
    return max;
}
int countDominantNodes(struct TreeNode* root) {
    int count = 0;
    dfs(root,&count);
    return count;
}