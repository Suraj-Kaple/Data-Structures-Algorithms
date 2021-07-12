// https://www.interviewbit.com/problems/profit-maximisation/

void maxHeapify(vector<int> &A, int i, int n){
    int l=2*i+1, r=2*i+2;
    if(l>n-1 and r>n-1) return;

    if(r<=n-1){
        if(A[i] < A[r])     swap(A[i],A[r]);
    }
    if(A[i] < A[l])     swap(A[i],A[l]);

    maxHeapify(A, l, n);
    if(r<=n-1)      maxHeapify(A, r, n);
}

int Solution::solve(vector<int> &A, int B) {
    int n=A.size(), profit=0;
    
    for(int i=ceil(n/2)-1; i>=0; i--)
        maxHeapify(A, i, n);
    (int i=0; i<B; i++){
        profit += A[0];
        A[0]--;
        maxHeapify(A, 0, n);
    }
    return profit;
}
