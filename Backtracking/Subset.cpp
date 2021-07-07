//https://www.interviewbit.com/problems/subset/

void build(vector<int> &A, int idx, vector<int> &holder, vector<vector<int> > &ans){
    ans.push_back(holder);
    int n=A.size();

    for(int i=idx; i<n; i++){
        holder.push_back(A[i]);
        build(A, i+1, holder, ans);
        holder.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(),A.end());
    int n=A.size();

    if(!n)  return {A};
    
    vector<vector<int> > ans;
    vector<int> holder;
    build(A, 0, holder, ans);
    return ans;
}
