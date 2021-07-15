// https://www.interviewbit.com/problems/balanced-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int solve(TreeNode* A) {
    if(A->left == NULL and A->right == NULL)
        return 1;
    
    int l = 0, r = 0;
    if(A->left != NULL)
        l = solve(A->left);
    if(A->right != NULL)
        r = solve(A->right);
    
    if(l==-1 or r==-1)  return -1;
    if(abs(l-r) > 1)    return -1;
    return 1 + max(l,r);    
}

int Solution::isBalanced(TreeNode* A){
    if(A == NULL)   return 1;
    int ret = solve(A);
    if(ret == -1)   return 0;
    return 1;
}