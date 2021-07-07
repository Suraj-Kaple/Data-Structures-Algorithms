// https://www.interviewbit.com/problems/combination-sum/

void build(vector<int> &A, int B, vector<vector<int> > &ans, int sum, int idx, vector<int> &temp){
    if(sum == B){
        ans.push_back(temp);
        return;
    }
    int n=A.size();
    for(int i=idx; i<n; i++){
        if(sum + A[i] > B)
            return;
        temp.push_back(A[i]);
        build(A, B, ans, sum+A[i], i, temp);
        temp.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());

    vector<vector<int> > ans;
    vector<int> temp;
    build(A, B, ans, 0, 0, temp);
    return ans;
}
