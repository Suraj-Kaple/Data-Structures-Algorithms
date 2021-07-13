// https://www.interviewbit.com/problems/valid-binary-search-tree/

// /**
//  * Definition for binary tree
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */

// int f(TreeNode* A, int grandParent){
//     cout<<A->val<<endl;
//     bool left=false, right=false;
//     if(A->left != NULL)     left = true;
//     if(A->right != NULL)    right = true;

//     int l=1, r=1;
//     if(A->val < grandParent){
//         if(left){
//             if(A->left->val < A->val and A->left->val < grandParent)   l = 1;
//             else    l=0;
//         }
//         if(right){
//             if(A->right->val > A->val and A->right->val < grandParent)  r = 1;
//             else    r = 0;
//         }
//     }
//     else if(A->val > grandParent){
//         if(left){
//             if(A->left->val < A->val and A->left->val > grandParent)   l = 1;
//             else    l=0;
//         }
//         if(right){
//             if(A->right->val > A->val and A->right->val > grandParent)  r = 1;
//             else    r = 0;
//         }
//     }

//     if(l and r){
//         if(left and l)  l = f(A->left, A->val);
//         if(right and r) r = f(A->right, A->val);
//         return l and r;
//     }
//     else
//         return 0;
// }

// int Solution::isValidBST(TreeNode* A) {
//     if(A == NULL)   return 1;
//     int l=1, r=1;
//     if(A->left != NULL){
//         if(A->left->val < A->val)    l = f(A->left, A->val);
//         else l = 0;
//     }
//     if(A->right != NULL){
//         if(A->right->val > A->val)   r = f(A->right, A->val);
//         else r=0;
//     }
//     return l and r;
// }

// Don't know why above code does not give right answer

int isValidBSTHelper(TreeNode* root, int minValue, int maxValue)
{
    if (!root)  
        return 1;
    if (root->val > minValue && root->val < maxValue
        && isValidBSTHelper(root->left, minValue, root->val)
        && isValidBSTHelper(root->right, root->val, maxValue))
        return 1;
    else
        return 0;
}
int Solution::isValidBST(TreeNode* A) {
    return isValidBSTHelper(A, INT_MIN, INT_MAX);
}

// This code fails if there is a node with value INT_MAX or INT_MIN

// The children of node on the left have to be less than their grandparent (the maxValue)
// The children of node on the right have to be greater than their grandparent (the minValue)