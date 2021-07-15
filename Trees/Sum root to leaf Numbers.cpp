// https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int summ;

void solve(TreeNode* A, int num){
    num = (num*10 + A->val) % 1003;
    if(A->left == NULL and A->right == NULL){
        summ  = (summ + num) % 1003;
        return;
    }
    
    if(A->left != NULL)
        solve(A->left, num);
    if(A->right != NULL)
        solve(A->right, num);
}

int Solution::sumNumbers(TreeNode* A) {
    summ = 0;
    solve(A, 0);
    return summ;
}
