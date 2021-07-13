// https://www.interviewbit.com/problems/invert-the-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* A) {
    queue<TreeNode*> q;
    q.push(A);
    TreeNode* temp;
    while(!q.empty()){
        if(q.front() != NULL){
            q.push(q.front()->right);
            q.push(q.front()->left);
            temp = q.front()->left;
            q.front()->left = q.front()->right;
            q.front()->right = temp;
        }
        q.pop();
    }
    return A;
}

// Do level order traversal and keep swaping children of current root (i.e. front of queue)
