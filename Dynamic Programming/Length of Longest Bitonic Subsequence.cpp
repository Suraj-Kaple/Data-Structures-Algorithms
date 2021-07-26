// https://www.interviewbit.com/problems/length-of-longest-subsequence/

vector<int> longestSubsequence(vector<int> A, int inc){
    if(!inc)
        reverse(A.begin(), A.end());
    
    int n=A.size();
    vector<int> dp(n,1);
    for(int i=1; i<n; i++){
        for(int j=i-1; j>=0; j--){
            if(A[i] > A[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    return dp;
}

int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    if(!n)  return 0;

    vector<int> inc, dec;
    inc = longestSubsequence(A, 0);
    dec = longestSubsequence(A, 1);
    reverse(dec.begin(), dec.end());

    int maxx = 2;
    for(int i=0; i<n; i++)
        maxx = max(maxx, inc[i] + dec[i]);

    return maxx-1;
}

// find longest increasing subsequence dp array and longest decreasing subsequence dp array
// then add dpInc[i] and dpDec[i]
// return max of this addition - 1      (-1 to include peak only once)