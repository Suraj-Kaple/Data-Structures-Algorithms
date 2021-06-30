// https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

int Solution::solve(string A) {
    int n = A.length();
    string B = A;
    reverse(B.begin(), B.end());

    int a=0, b=0, started=0, ans;
    while(b < n){
        if(A[a] == B[b]){
            if(!started)
                ans = b;
            a++;
            b++;
            started = 1;
        }
        else if(A[a] != B[b]){
            if(!started)	// if not started, a will be 0, so increase b
                b++;
            else{
                a=0;
                started = 0;
            }
        }
    }
    return ans;
}
// a can be used as started

/***********************************************************/

// same logic different implementation
int Solution::solve(string A) {
    int maxlen = 1, n = A.length(), end=n-1, ans;
    while(end > 0){
        int start = 0, flag = 1;
        while(start < end and flag){
            if(!(A[start] == A[end])){
                flag = 0;
                if(!start)  end--;	// if start is 0 (which here means first comarison is unequal), increase b
            }
            else{
                if(!start)
                    ans = end;
                start++;
                end--;
            }
        }
        if(flag){	// flag indicates whether the cur substring is palindrom or not
            maxlen = ans+1;
            break;
        }
    }
    return n - maxlen;
}

// in both the solutions, b/end need not be reset to next/prev index.
// reaching position b/end implies that elements before/after b/end either do not match or are all equal and will definitely match.
