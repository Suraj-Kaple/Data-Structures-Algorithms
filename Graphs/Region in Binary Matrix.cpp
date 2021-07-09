// https://www.interviewbit.com/problems/region-in-binarymatrix/

int n, m;

void dfs(vector<vector<int> > &A, vector<vector<int> > &visited, int i, int j, int* count){
    visited[i][j] = 1;
    if(A[i][j]){
        // cout<<i<<" "<<j<<endl;
        (*count) += 1;
        if(i-1>=0){
            if(j-1>=0 and A[i-1][j-1] and !visited[i-1][j-1])
                dfs(A, visited, i-1,j-1, count);
            if(A[i-1][j] and !visited[i-1][j])
                dfs(A, visited, i-1,j, count);
            if(j+1<m and A[i-1][j+1] and !visited[i-1][j+1])
                dfs(A, visited, i-1,j+1, count);
        }

        if(j-1>=0 and A[i][j-1] and !visited[i][j-1])
            dfs(A, visited, i,j-1, count);
        if(j+1<m and A[i][j+1] and !visited[i][j+1])
            dfs(A, visited, i,j+1, count);
        
        if(i+1<n){
            if(j-1>=0 and A[i+1][j-1] and !visited[i+1][j-1])
                dfs(A, visited, i+1,j-1, count);
            if(A[i+1][j] and !visited[i+1][j])
                dfs(A, visited, i+1,j, count);
            if(j+1<m and A[i+1][j+1] and !visited[i+1][j+1])
                dfs(A, visited, i+1,j+1, count);
        }
    }

    return;
}

int Solution::solve(vector<vector<int> > &A) {
    n=A.size(), m=A[0].size();
    vector<vector<int> > visited(n, vector<int> (m,0));
    int maxx = 1, currCount;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            currCount = 0;
            if(!visited[i][j]){
                dfs(A, visited, i, j, &currCount);
                maxx = max(maxx, currCount);
            }
        }
    }
    return maxx;
}
