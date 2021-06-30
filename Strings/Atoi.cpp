// interviewbit.com/problems/atoi/

int Solution::atoi(const string A) {
    int started=0, ans=0;
    bool isNeg = false;
    
    for(int i=0; i<A.length(); i++){
        if(A[i] == ' '){
            if(started)
                return isNeg ? -ans : ans;
            else{
                if(i and (A[i-1]=='+' or A[i-1] == '-'))	// if before the current whitespace there was '+' or '-', then return 0
                    return 0;
            }
        }
        if(A[i] >= '0' and A[i] <= '9'){
            if(!started and i and A[i-1] == '-')	// if there was '-' before the starting digit, then isNeg=true
                isNeg = true;
            
            // way to check if multiplication of int by 10 will lead to overflow
            if(ans > INT_MAX/10)
                return isNeg ? INT_MIN : INT_MAX;
            else if(ans == INT_MAX/10){
                if(isNeg and A[i] - '0' > 8)    return INT_MIN;
                else if(!isNeg and A[i] - '0' > 7) return INT_MAX;
            }

            ans *= 10;
            ans += (A[i] - '0');
            started = 1;
        }
        else{
            if(!started){
                if(A[i] != '+' and A[i] != '-')	// do not return 0 directly if '+' ot '-' is found
                    return 0;
            }
            else{
                return isNeg ? -ans : ans;
            }
        }
    }
    if(started) return isNeg ? -ans : ans;
    return 0;
}
