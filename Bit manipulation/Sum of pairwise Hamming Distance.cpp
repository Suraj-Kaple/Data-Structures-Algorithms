// interviewbit.com/problems/sum-of-pairwise-hamming-distance/

int Solution::hammingDistance(const vector<int> &A) {
    int n=A.size(), ans = 0, temp = 1;
    long long zero = 0, one = 0;	// long long because zero*one can exceed 10^9
    
    for(int j=1; j<=32; j++){
        for(int i=0; i<n; i++){
            if(temp & A[i])	// check if jth bit is set
                one++;
            else
                zero++;
        }
        // cout<<zero<<" "<<one<<endl;
        ans = ((ans) + ((zero)*(one)*2)%1000000007)%1000000007;
	// https://www.geeksforgeeks.org/modulo-1097-1000000007/
        zero = 0; one = 0;
        temp = temp << 1;
    }
    return ans;
}
