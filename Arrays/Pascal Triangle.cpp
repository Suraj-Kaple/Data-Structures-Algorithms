//https://www.interviewbit.com/problems/pascal-triangle/

vector<vector<int> > Solution::solve(int A) {
    vector<vector<int> > v(A);
    if(A == 0)  return v;
    v[0] = {1};
    for(int i=1; i<A; i++){
        v[i] = {1};
        for(int j=1; j<i; j++){
            int num = v[i-1][j] + v[i-1][j-1];
            v[i].push_back(num);
        }
        v[i].push_back(1);
    }
    return v;
}
