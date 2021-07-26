// https://www.interviewbit.com/problems/tushars-birthday-party/

int Solution::solve(const vector<int> &cap, const vector<int> &fc, const vector<int> &cost) {
    int max_cap = *max_element(cap.begin(),cap.end()), d = fc.size(), f = cap.size();
    vector<int> dp(max_cap+1, INT_MAX);
    dp[0] = 0;
    
    // INT_MAX implies currently the capacity i in dp[i] cannot be satisfied

    for(int i=0; i<d; i++){     // for every dish
        for(int j=fc[i]; j<max_cap+1; j++){     // for every possible capacity >= current filling capacity till max_capacity
            if(dp[j - fc[i]] != INT_MAX)     // if their is a soln. for the capacity left after eating current dish
                dp[j] = min(dp[j - fc[i]] + cost[i], dp[j]);    // take minimum cost between current dish eaten and current dish not eaten
        }
    }

    int total_sum = 0;
    for(int i=0; i<f; i++){
        total_sum += dp[cap[i]];    // add cost for given capacities
    }
    return total_sum;
}

// can also do knapsack for every freind