// https://www.interviewbit.com/problems/min-depth-of-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int minn;
void solve(TreeNode* A, int level){
    if(A->left == NULL and A->right == NULL){
        minn = min(minn, level);
        return;
    }

    if(A->left != NULL)
        solve(A->left, level+1);
    if(A->right != NULL)
        solve(A->right, level+1);
}

int Solution::minDepth(TreeNode* A) {
    if(A == NULL)   return 0;
    minn = INT_MAX;
    solve(A, 1);
    return minn;
}
