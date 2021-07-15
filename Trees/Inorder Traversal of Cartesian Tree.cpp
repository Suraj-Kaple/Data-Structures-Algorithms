// https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* f(vector<int> &A, int start, int end){
    if(start > end)
        return NULL;
    
    int max_idx = max_element(next(A.begin(),start), next(A.begin(),end+1)) - A.begin();
    TreeNode* root = new TreeNode(A[max_idx]);
    root->left = f(A, start, max_idx-1);
    root->right = f(A, max_idx+1, end);

    return root;
}

TreeNode* Solution::buildTree(vector<int> &A) {
    int n=A.size();
    return f(A, 0, n-1);
}

// max element in array becomes the root.
// recurr for left and right sub-arrays
// they form the left and right children respectively