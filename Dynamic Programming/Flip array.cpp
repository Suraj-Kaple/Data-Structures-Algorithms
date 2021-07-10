// https://www.interviewbit.com/problems/flip-array/
// knapsack approach

int Solution::solve(const vector<int> &A) {
    int n=A.size(), summ=0;
    for(auto x:A)   summ += x;
    // cout<<summ<<endl;

    vector<int> negations(summ+1, -1);  // indices of negations will be possible value of sum of array
    // -1 will indicate that for negations[i]=-1, sum=i is not possible
    
    negations[summ] = 0;    // because if we add all elements, we get sum = summ; 0 indicates 0 negations are required to have sum = summ
    for(int i=0; i<n; i++){ // remove A[i] from current possible sums
        for(int j=0; j<=summ; j++){ // look through current possible sums
            int newSum = j - (2*A[i]);  // newSum will be currSum - (the number to be negated i.e. A[i]) - (additional loss of A[i] becoz A[i] is negated)
            if(newSum >= 0 and negations[j] != -1)  // if newSum is non-negative and if currSum was achieved earlier
                if(negations[newSum] == -1) // if newSum was not achieved earlier
                    negations[newSum] = negations[j] + 1;   // * see down
                else    // if newSum was achieved earlier
                    negations[newSum] = min(negations[j] + 1,negations[newSum]);    // keep the minimum #negations
        }
    }
    for(int i=0; i<summ; i++){
        // cout<<negations[i]<<" ";
        if(negations[i] >= 0)
            return negations[i];
    }
    return 0;
}

// * #negations for newSum = #negations for currSum + 1 (1 is the negation of A[i])