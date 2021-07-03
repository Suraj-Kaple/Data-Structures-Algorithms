// https://www.interviewbit.com/problems/matrix-search/

int binarySearch(vector<vector<int>> &A, int B, int isRow, int size, int idx){
    int low = 0, high = size-1;

    while(low <= high){
        int mid = (low + high)/2;

        if(!isRow){
            if(A[mid][idx] < B)     low = mid+1;
            else{
                if(mid){
                    if(A[mid-1][idx] < B)  return mid;
                    else    high = mid-1;
                }
                else    return mid;
            }
        }
        else{
            if(A[idx][mid] == B)   return mid;
            else if(A[idx][mid] < B)    low = mid+1;
            else    high = mid-1;
        }
    }
    return -1;
}

// isRow tells if binarySearch is applied in a row (1) or column (0)

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int N = A.size(), M = A[0].size();

    int row = binarySearch(A, B, 0, N, M-1);    // search smallest number greater than B in last column
    if(row == -1)   return 0;   // if no number is greater than B, return 0

    // else search for B in row A[row]

    int col = binarySearch(A, B, 1, M, row);    // search B in A[row]
    if(col == -1)   return 0;

    return 1;
}
