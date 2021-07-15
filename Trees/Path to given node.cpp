// https://www.interviewbit.com/problems/path-to-given-node/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int findPath(vector<int> &ans, TreeNode* A, int B){
    if(A == NULL)
        return 0;
    ans.push_back(A->val);
    if(A->val == B)
        return 1;
    
    int l = findPath(ans, A->left, B), r=0;
    if(!l)  r = findPath(ans, A->right, B);
    if(l or r)
        return 1;
    ans.pop_back();
    return 0;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    findPath(ans, A, B);
    return ans;
}
