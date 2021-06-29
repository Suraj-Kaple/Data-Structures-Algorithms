// https://www.interviewbit.com/problems/next-similar-number/

string Solution::solve(string A) {
    int dip = -1;
    for(int i=A.length()-1; i>0; i--){
        if(A[i] - '0' > A[i-1] - '0'){	// Find first index from behind where we encounter a dip
            dip = i-1;
            break;
        }
    }
    if(dip == -1)   return "-1";	// if there is no dip, the curr number is greatest possible

    int minn_idx = dip+1;
    for(int i=dip+2; i<A.length(); i++){
	// Find smallest digit > A[dip] from dip+1 till end
        if(A[i] > A[dip] and A[i] < A[minn_idx])
            minn_idx = i;
    }
    swap(A[dip], A[minn_idx]);	// swap this smallest digit with A[dip] (so that the new number is > curr number)
    sort(next(A.begin(),dip+1), A.end());	// sort so that the new number is smallest
    return A;
}
