// https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int> > ans;
    stack<TreeNode*> s1, s2;
    s2.push(A);
    ans.push_back({A->val});
    while(!s1.empty() or !s2.empty()){
        vector<int> temp;
        if(s1.empty()){
            while(!s2.empty()){
                if(s2.top()->right != NULL){
                    s1.push(s2.top()->right);
                    temp.push_back(s2.top()->right->val);
                }
                if(s2.top()->left != NULL){
                    s1.push(s2.top()->left);
                    temp.push_back(s2.top()->left->val);
                }
                s2.pop();
            }
        }
        else if(s2.empty()){
            while(!s1.empty()){
                if(s1.top()->left != NULL){
                    s2.push(s1.top()->left);
                    temp.push_back(s1.top()->left->val);
                }
                if(s1.top()->right != NULL){
                    s2.push(s1.top()->right);
                    temp.push_back(s1.top()->right->val);
                }
                s1.pop();
            }
        }
        if(temp.size() > 0)
            ans.push_back(temp);
    }
    return ans;
}

// Alternate soln. using single queue

// vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {

//     vector<vector<int>> ans;
//     if(!root)  return ans;
    
//     queue<TreeNode*> q;
//     q.push(root);
//     int level = 1;
    
//     while(!q.empty()){
//         int n = q.size();
//         vector<int> v;
//         for(int i=0; i<n; i++){
//             TreeNode* temp = q.front();
//             v.push_back(temp->val);
//             if(temp->left)  q.push(temp->left);
//             if(temp->right)  q.push(temp->right);
//             q.pop();
//         }
//         if(level%2 == 0) reverse(v.begin(), v.end());
//         level++;
//         ans.push_back(v);
//     }
//     return ans;
// }