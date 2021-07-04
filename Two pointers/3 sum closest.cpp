// https://www.interviewbit.com/problems/3-sum/

int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int n = A.size(), start = 0, last = n-1, min_diff = INT_MAX, ans, flag=1;

    while(start < n-2 and flag){
        if(!(last - start >= 2))    break;
        int p1 = start+1, p2 = last;

        while(p1 < p2){
            int sum = A[start] + A[p1] + A[p2], curr_diff = abs(B - sum);
            if(curr_diff < min_diff){
                min_diff = curr_diff;
                ans = sum;
            }
            
            if(sum > B){
                p2--;
                // if(p1 - start <= 2)
                //     last = p2;
            }
            else if(sum < B)
                p1++;
            else{
                flag = 0;
                break;
            }
        }
        start++;
    }
    return ans;
}