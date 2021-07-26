// https://www.interviewbit.com/problems/repeating-subsequence/

int Solution::anytwo(string s) {
    int n = s.length();
    vector<vector<int> > dp(n+1, vector<int>(n+1,0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(s[i-1] == s[j-1] and i!=j)
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=n; j++)
    //         cout<<dp[i][j]<<" "; 
    //     cout<<endl;
    // }
        
    return dp[n][n]<=1 ? 0 : 1;
}

// same approach as longest common subsequence problem
// only difference is that treat chars to be unequal when i==j
