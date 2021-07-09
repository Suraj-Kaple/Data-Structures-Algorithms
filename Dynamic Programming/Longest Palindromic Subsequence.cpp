// https://www.interviewbit.com/problems/longest-palindromic-subsequence/

int Solution::solve(string A) {
    int n=A.length();
    vector<vector<int> > LPS(n, vector<int> (n));   // Longest palindromic subsequence

    // LPS[i][j] is the longest palindromic subsequence for string A[i...j]
    // tabulate
    for(int diff=0; diff<n; diff++){    // diff between start (i) and end (j) indices
        int i=0, j=i+diff;
        while(j<n){
            if(i == j)  // if string in consideration is of length 1
                LPS[i][j] = 1;  // then it's LPS is 1
            else if(A[i] == A[j])   // if first and last chars of string are equal
                LPS[i][j] = LPS[i+1][j-1] + 2;  // LPS is 2 + LPS of string without first and last chars
            else    // if first and last chars of string are not equal
                LPS[i][j] = max(LPS[i+1][j], LPS[i][j-1]);  // LPS is maximum LPS of string without first char and string without last char
            i++; j++;
        }
    }
    return LPS[0][n-1]; // LPS of string from 0 to n-1 (which is A)
}

// https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
// https://youtu.be/TLaGwTnd3HY

// if first and last char of a string are equal
    // LPS is 2 + LPS of string without first and last chars
// else
    // LPS is max LPS of string without first char and string without last char