// https://www.interviewbit.com/problems/sorted-permutation-rank/

// the problem is similar to finding position of string in dictionary
// string includes any character but only once

int factorial(int n){
    return (n==1 || n==0) ? 1 : ((n%1000003)*(factorial(n-1) % 1000003));
}

int Solution::findRank(string A) {
    string B = A;
    sort(B.begin(), B.end());
    int n = A.length(), ans = 1;    // default value of ans = 1

    for(int i=0; i<n; i++){
        int less_than_Ai = distance(B.begin(), find(B.begin(),B.end(), A[i]));  // find index of A[i] in B
        ans = ans + (less_than_Ai * factorial(n-1-i)) % 1000003;
        B.erase(next(B.begin(), less_than_Ai)); // erase A[i] from B
    }
    return ans%1000003;
}

// less_than_Ai means number of characters not used and are less that A[i]
// the index (say j) in B tells the value of less_than_Ai for (j+1)th char