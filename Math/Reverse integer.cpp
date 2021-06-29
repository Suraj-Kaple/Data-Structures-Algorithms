// https://www.interviewbit.com/problems/reverse-integer/

long long reverseINT(long long a){
    long long ans = 0;
    while(a > 0){
        int unit = a%10;
        ans = ans*10 + unit;
        a = a/10;
    }
    return ans;
}

int Solution::reverse(int A) {
    long long a = A;
    bool isNeg = false;
    if(a<0){
        isNeg = true;
        a = abs(a);
    }
    long long rev_a = reverseINT(a);

    if(isNeg and -rev_a < INT_MIN)  return 0;
    else if(rev_a > INT_MAX)    return 0;
    else{
        return isNeg ? -rev_a : rev_a;
    }
}
