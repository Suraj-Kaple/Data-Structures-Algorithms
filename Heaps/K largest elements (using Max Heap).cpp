// https://www.interviewbit.com/problems/k-largest-elements/

void heapify(vector<int> &A, int i, int n){
    int l = 2*i+1, r=2*i+2, largest=i;

    if(r<=n-1 and A[largest] < A[r])
        largest=r;
    
    if(l<=n-1 and A[largest] < A[l])
	largest=l;
 
    if(largest != i){
        swap(A[i], A[largest]);
        heapify(A, largest, n);
    }    
}
 
void buildHeap(vector<int> &A){
    int n=A.size();
    int start = n/2 - 1;
    for(int i=start; i>=0; i--){
        heapify(A, i, n);
    }
}
 
int pop(vector<int> &A, int n){
    int maxx = A[0];
    swap(A[0], A[n-1]);
    heapify(A, 0, n-1);
    return maxx;
}
 
vector<int> Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    buildHeap(A);

    vector<int> ans;
    for(int i=0; i<B; i++)
        ans.push_back(pop(A, n-i));
    return ans;
}