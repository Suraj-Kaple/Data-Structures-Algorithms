// https://www.interviewbit.com/problems/kth-smallest-element-in-the-array/

int Solution::kthsmallest(const vector<int> &A, int k) {
    int n = A.size(), lo = *min_element(A.begin(),A.end()), hi = *max_element(A.begin(),A.end());
    while(lo <= hi){
        int mid = lo + (hi - lo)/2, countLessThan=0, countEqualTo=0;

        for(int i=0; i<n; i++){
            if(A[i] < mid)
                countLessThan++;
            else if(A[i] == mid)
                countEqualTo++;
            if(countLessThan > k)
                break;
        }

        if(countLessThan < k and countLessThan+countEqualTo>=k)
            return mid;
        else if(k <= countLessThan)
            hi = mid-1;
        else if(k>countLessThan + countEqualTo)
            lo = mid+1;
    }
}

// use binary search on range of values in array
// countLessThan is never checked for equality with k because if mid is not in A, then answer would be mid which is wrong