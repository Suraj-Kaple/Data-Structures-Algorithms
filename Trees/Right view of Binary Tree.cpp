// https://www.interviewbit.com/problems/right-view-of-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> ans;

void getRight(TreeNode* A, int level){
    if(A == NULL)
        return;
    
    if(level > ans.size())
        ans.push_back(A->val);
    getRight(A->right, level+1);
    getRight(A->left, level+1);
}

vector<int> Solution::solve(TreeNode* A) {
    ans.resize(0);
    getRight(A, 1);
    return ans;
}
