// Given a string A, find length of the longest repeating 
// sub-string such that the two sub-strings don't overlap

int Solution::anytwo(string s) {
    int n = s.length();
    vector<vector<int> > dp(n, vector<int>(n,0));

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(s[i] == s[j])
                dp[i][j] = 1; 
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<dp[i][j]<<" "; 
    //     }
    //     cout<<endl;
    // }

    int maxx = 0;
    for(int i=0; i<n-1; i++){
        int count = 0, started = 0;
        for(int j=n-i-2; j>=0; j--){
            if(!started){
                if(dp[j][j+1+i] == 1){
                    started = 1;
                    count++;
                }
            }
            else{
                if(dp[j][j+1+i] == 1)
                    count++;
                else{
                    maxx = max(count, maxx);
                    started = 0;
                    count = 0;
                }
            }
        }
        if(started)
            maxx = max(count, maxx);
    }
    return maxx;
}
