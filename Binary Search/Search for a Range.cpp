// https://www.interviewbit.com/problems/search-for-a-range/

int bSeacrh(const vector<int> &A, int B, int start){
    int n = A.size(), low=0, high=n-1;

    while(low <= high){
        int mid = (low + high)/2;

        if(A[mid] == B and start){
            if(mid){
                if(A[mid-1] != B)   return mid;
                else    high = mid-1;
            }
            else    return mid;
        }
        else if(A[mid] == B and !start){
            if(mid < n-1){
                if(A[mid+1] != B)   return mid;
                else    low = mid+1;
            }
            else    return mid;
        }
        else if(A[mid] < B)     low = mid+1;
        else    high = mid-1;
    }
    return -1;
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    vector<int> v(2);
    v[0] = bSeacrh(A, B, 1);
    v[1] = bSeacrh(A, B, 0);
    return v;
}
