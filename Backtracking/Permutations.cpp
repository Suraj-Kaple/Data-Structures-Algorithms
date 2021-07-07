// https://www.interviewbit.com/problems/permutations/

void build(vector<int> &A, int left, int right, vector<vector<int> > &ans){
    if(left == right){
        ans.push_back(A);
        return;
    }

    for(int i=left; i<=right; i++){
        swap(A[left], A[i]);
        build(A, left+1, right, ans);
        swap(A[left], A[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    int n=A.size();
    vector<vector<int> > ans;
    build(A, 0, n-1, ans);
    return ans;
}
