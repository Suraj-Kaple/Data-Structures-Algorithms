// https://www.interviewbit.com/problems/minimum-parantheses/

int Solution::solve(string A) {
    int ans = 0, count = 0, n = A.length();
    for(int i=0; i<n; i++){
        if(A[i] == '('){
            if(count < 0)   // this means that an '(' has come after exceeded ')'s [so we begin a new counting session]
                count = 1;
            else
                count++;
        }
        else{
            count--;
            if(count < 0){  // this means that ')' have exceeded '(' in current session and hence an '(' is must [so increment by 1]
                ans += 1;
            }
        }
    }
    if(count > 0)
        return ans + count; // add the required number of ')'
    return ans;
}

// if count > 0, '(' are more
// if count < 0, ')' are more [in this case, for every ')', there is need of an '(']