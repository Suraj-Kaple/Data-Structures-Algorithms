// https://www.interviewbit.com/problems/pair-with-given-difference/

int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int n = A.size(), p1 = 0, p2 = p1+1, flag=1;
    B = abs(B); // as each pair can give a non-negative and negative ans, find pair for only non-negative difference

    while(p2 < n and flag){
        if(p1 == p2)
            p2++;
        else if(A[p2] - A[p1] == B)
            flag = 0;
        else if(A[p2] - A[p1] < B)
            p2++;
        else
            p1++;
    }
    if(flag)    return 0;
    return 1;   
}