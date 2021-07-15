// https://www.interviewbit.com/problems/reverse-level-order/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    queue<TreeNode*> q;
    stack<TreeNode*> s;
    vector<int> ans;
    q.push(A);
    s.push(A);

    while(!q.empty()){
        if(q.front()->right != NULL){
            q.push(q.front()->right);
            s.push(q.front()->right);
        }
        if(q.front()->left != NULL){
            q.push(q.front()->left);
            s.push(q.front()->left);
        }
        q.pop();
    }

    while(!s.empty()){
        ans.push_back(s.top()->val);
        s.pop();
    }
    return ans;
}
