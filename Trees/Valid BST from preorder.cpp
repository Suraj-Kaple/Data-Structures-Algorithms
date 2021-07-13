// https://www.interviewbit.com/problems/valid-bst-from-preorder/

int Solution::solve(vector<int> &A) {
    stack<int> s;   // s.top is the node for which we check if the incoming node can be its child or not
    int root = INT_MIN, n=A.size();
    
    for(int i=0; i<n; i++){
        // if there is any incoming node with value less than root, then it cannot be included in the BST
        if(A[i] < root) return 0;
        
        while(!s.empty() and s.top() < A[i]){
            root = s.top();
            s.pop();
            // now values less than root cannot be present in the array and 
            // this marks the completion of left subtree of current s.top()     (the current top of stack)

        }
        s.push(A[i]);   // push A[i] to stack so that we can check if incoming node is the child of A[i] or not
    }
    return 1;
}

// https://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/