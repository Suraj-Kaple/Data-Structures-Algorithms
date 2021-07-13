// https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int ans;

void inorderSearch(TreeNode* A, int B, int* count){
    if(A == NULL)   return ;

    inorderSearch(A->left, B, count);
    (*count)++;
    if(*count == B){
        ans = A->val;
        return;
    }
    inorderSearch(A->right, B, count);
}

int Solution::kthsmallest(TreeNode* A, int B) {
    int count=0;
    inorderSearch(A, B, &count);
    return ans;
}

// do inorder traversal. Instead of printing node value, increase count and check if it is equal to B