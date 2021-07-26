// https://www.interviewbit.com/problems/path-sum/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int Solution::hasPathSum(TreeNode* A, int B) {
    if(A == NULL)   return 0;

    if(A->left == NULL and A->right == NULL)
        return A->val == B;
    
    return hasPathSum(A->left, B - A->val) or hasPathSum(A->right, B - A->val);
}
