// https://www.interviewbit.com/problems/k-largest-elements/

void minHeapify(vector<int> &A, int i, int n){
    int l = 2*i+1, r=2*i+2, smallest=i;
    
	// find smallest among the three nodes
    if(r<=n-1 and A[smallest] > A[r])
        smallest = r;
    if(l<=n-1 and A[smallest] > A[l])
		smallest = l;
    
    if(smallest != i){
    	swap(A[i], A[smallest]);
    	minHeapify(A, smallest, n);
	}
}

void buildHeapTillB(vector<int> &A, int B){     // runs in O(B) (might seem Blog(B))
    int start = B/2 - 1;    // start from the bottom-right-most non leaf node
    for(int i=start; i>=0; i--){
        minHeapify(A, i, B);
    }
}

vector<int> Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    buildHeapTillB(A, B);   // build minHeap for first B nodes

    for(int i=B; i<n; i++){
        if(A[i] > A[0]){
            swap(A[0], A[i]);
            minHeapify(A, 0, B);
        }
    }

    vector<int> ans;
    ans.assign(A.begin(), next(A.begin(),B));
    return ans;
}

// 1. Build a Min Heap MH of the first k elements (A[0] to A[k-1]) of the given array. O(k)
// 2. For each element, after the kth element (arr[k] to arr[n-1]), compare it with root of MH.
//    If the element is greater than the root then make it root and call minHeapify for MH
//    Else ignore it.
// The step 2 is O((n-k)*logk)
// 3. Finally, MH has k largest elements and root of the MH is the kth largest element.
// Time Complexity: O(k + (n-k)Logk) without sorted output. If sorted output is needed then O(k + (n-k)Logk + kLogk)
