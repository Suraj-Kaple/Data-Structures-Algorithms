// https://www.interviewbit.com/problems/0-1-knapsack/

int Solution::solve(vector<int> &V, vector<int> &W, int C) {
    int n=V.size();
    vector<vector<int> > value(n+1, vector<int> (C+1));
    // rows correspond to items (from 0 items to n items)
    // cols correspond to capacity (from 0 to C)

    // consider items start from 1 to n
    // tabulate
    for(int i=0; i<=n; i++){
        for(int j=0; j<=C; j++){
            if(!i or !j)    // if #items or capacity is 0, value will be 0
                value[i][j] = 0;
            else{
                if(j-W[i-1] >= 0)   // if we can choose item i
                    value[i][j] = max(value[i-1][j-W[i-1]] + V[i-1], value[i-1][j]);    // * see down
                else    // if we can't choose item i
                    value[i][j] = value[i-1][j];    // assign value when items are till i-1 and capacity is j
            }
        }
    }

    // printing dp table
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=C; j++){
    //         cout<<value[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    return value[n][C];
}

// * assign max of (value when item i is chosen, value when item i is not chosen)
// value when item i is chosen = value of item i +(value when items are till i-1 and capacity is currCapacity - wt. of item i)
// value when item i is not chosen = value when items are till i-1 and capacity is currCapacity
