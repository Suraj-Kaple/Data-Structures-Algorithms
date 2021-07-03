// https://www.interviewbit.com/problems/matrix-median/

int Solution::findMedian(vector<vector<int> > &A) {
	int low=0, high=(int)1e9, N = A.size(), M = A[0].size();
	
	while(low <= high){
		int mid = low + (high - low)/2, count = 0;
		// count is number of elements in matrix which are less than mid
		for(int i=0; i<N; i++){
			count += lower_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
			// incrementing count by no. of elements in ith row which are less than mid
		}
		// if(count == N*M/2)	return mid;	
		// returning mid can return some number less than actual median which is not present in the matrix. For given test case, it will return 4
		if(count <= N*M/2)	low = mid+1;
		else high = mid-1;
	}
	return low-1;
}


// testcase
// 1 3 5
// 2 6 9
// 3 6 9

// for 4 and 5 we get count == 4, but 4 is not present in matrix.
// from the set of elements for which count is equal, the maximum value element will be in matrix !
// because lower bound of all numbers in the set is the max value element
// in this case max(4,5) = 5 which is present in matrix
