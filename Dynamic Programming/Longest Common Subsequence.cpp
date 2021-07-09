// https://www.interviewbit.com/problems/longest-common-subsequence/

int Solution::solve(string A, string B) {
    int n=A.length(), m=B.length();
    vector<vector<int> > LCS(n+1, vector<int> (m+1));   // Longest common subsequence

    // LCS[i][j] is longest common subsequence of strings A[0...i-1] and B[0...j-1]
    // tabulation (bottom-up)
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            if(!i or !j)    // when either of strings is empty
                LCS[i][j] = 0;  // then LCS is also empty (of length 0)
            else if(A[i-1] == B[j-1]){  // if last char of both strings is equal
                LCS[i][j] = LCS[i-1][j-1] + 1;  // then add 1 to LCS of both strings without last char and assign it to LCS of current strings
            }
            else{   // if last char of both strings is not equal
                LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]);  // assigne LCS of curr strings as the max LCS when either of the strings do not have the last char
            }
        }
    }
    return LCS[n][m];   // stores LCS of A[0...n-1] and B[0...m-1]
}

// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
// https://youtu.be/HgUOWB0StNE