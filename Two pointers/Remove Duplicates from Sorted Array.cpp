// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/

int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size();
    if(n<2) return n;

    int insert_at=1, check_for=1;
    while(check_for < n){
        if(A[check_for] != A[check_for-1]){
            A[insert_at] = A[check_for];
            insert_at++;
        }
        check_for++;
    }
    return insert_at;
}
