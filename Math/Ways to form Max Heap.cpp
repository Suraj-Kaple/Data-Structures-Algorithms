// https://www.interviewbit.com/problems/ways-to-form-max-heap/

#define M 1000000007
#define max_n 100   // max value of n given in constraints
#define ll long long

vector<vector<ll> > C(max_n+1, vector<ll> (max_n+1, -1));   // C[i][j] = iCj
vector<ll> dp(max_n+1, -1);     // dp[i] = T(i)

ll nCr(ll n, ll r){
    if (r==0 or r==n)   return 1;
    if(C[n][r] != -1)   return C[n][r];
    C[n][r] = (nCr(n-1,r-1)%M + nCr(n-1,r)%M)%M;
    return C[n][r];
}

ll T(ll n){
    if(n <= 2)  return 1;   // for two nodes, #heaps = 1
    if(dp[n] != -1) return dp[n];   // directly use stored value dp[n] = T(n)

    // lastLevelNodes is #nodes in last level of current heap
    ll h = log2(n), lastLevelNodes = n - pow(2,h) + 1, l, r;    // l + r = n - 1
    if(lastLevelNodes > pow(2,h)/2) // if lastLevelNodes > half of maxPossible nodes in last level
        l = pow(2,h) - 1;   // number of nodes in left heap will be 2^h - 1
    else
        l = pow(2,h-1) - 1 + lastLevelNodes;    // number of nodes in left heap will be nodes till level (h-1) + lastLevelNodes
    r = n - 1 - l;

    dp[n] = (((nCr(n-1, l) * T(l)) %M) * T(r))%M;   // T(n) = (n-1)Cl * T(l) * T(r)
    return dp[n];

    // T(l) and T(r) are subproblems
}

int Solution::solve(int n) {
    ll N=n;
    return (int)T(N)%M;
}

// https://www.geeksforgeeks.org/number-ways-form-heap-n-distinct-integers/