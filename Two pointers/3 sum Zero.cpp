// https://www.interviewbit.com/problems/3-sum-zero/

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(A.begin(),A.end());
    int n=A.size(), start=0, last=n-1, prev_start=-1;
    vector<vector<int>> ans;

    while(start < n-2 and A[start] <= 0){
        long long num1 = A[start];
        if(prev_start != -1 and A[prev_start] == A[start]){
            start++;
            continue;
        }
        int p1 = start+1, p2 = last, prev_p1=-2, prev_p2=-1;

        while(p1 < p2){
            // if(!A[start] and A[p1] > 0)  // if A[start] is 0 and A[p1] is positive, no need to proceed
            //     break;
            // else if(A[start] < 0 and A[p2] <= 0) // if A[start] is negative and A[p2] is non-positive, no need to proceed
            //     break;
            
            if(prev_p1 != -2 and A[prev_p1] == A[p1]){
                p1++;
                continue;
            }
            if(prev_p2 != -1 and A[prev_p2] == A[p2]){
                p2--;
                continue;
            }
            long long num2 = A[p1], num3 = A[p2], sum = (num1 + num3) + num2;
            // long long required to avoid integer overflow
            if(!sum){
                ans.push_back({A[start], A[p1], A[p2]});
                prev_p2 = p2;
                prev_p1 = p1;
                p2--;
                p1++;
            }
            else if(sum > 0){
                prev_p2 = p2;
                p2--;
            }
            else if(sum < 0){
                prev_p1 = p1;
                p1++;
            }
        }
        prev_start = start;
        start++;
    }
    return ans;
}

// prev have been used to avoid duplicates

// if commented if-else is kept, then first adding num1 and num3 and later num2 reduces the chance of overflow.
// But there are still some cases where integer overflow occurs. So better use long long.