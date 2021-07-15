//https://www.interviewbit.com/problems/remove-half-nodes/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int postOrder(TreeNode* A){
    if(A == NULL)
        return 0;
    
    int l = postOrder(A->left), r = postOrder(A->right);
    if(l ^ r){
        if(l)
            *(A) = *(A->left);
        else if (r)
            *(A) = *(A->right);
    }
    return 1;
}

TreeNode* Solution::solve(TreeNode* A) {
    int ret = postOrder(A);
    return A;
}

// Alternate
// TreeNode* Solution::solve(TreeNode* A) {
//     if(A->left == NULL && A->right == NULL)return A;
//     if(A->left == NULL)
//         return solve(A->right);
//     if(A->right == NULL)
//         return solve(A->left);
//     A->left = solve(A->left);
//     A->right = solve(A->right);
//     return A;
// }
