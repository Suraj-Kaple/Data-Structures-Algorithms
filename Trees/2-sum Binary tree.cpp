// https://www.interviewbit.com/problems/2sum-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int search(TreeNode* A, int x, TreeNode* node){
    if(A == NULL)
        return 0;
    
    if(x < A->val)
        return search(A->left, x, node);
    else if(x > A->val)
        return search(A->right, x, node);
    else{
        if(A != node)    return 1; 
        else    return 0;     // when temp == q.front(), return 0 because we need two different nodes
    }
}

int Solution::t2Sum(TreeNode* A, int B) {
    queue<TreeNode*> q;
    q.push(A);

    int temp;
    while(!q.empty()){
        if(q.front() != NULL){
            q.push(q.front()->left);
            q.push(q.front()->right);
            temp = B - q.front()->val;
            if(temp > 0 and search(A, temp, q.front())){
                return 1;
            }
        }
        q.pop();
    }
    return 0;
}

// do level order traversal for selecting node1
// search the tree for node with value = B - node1.val
