int Solution::solve(vector<int> &A, int B) {
    int n=A.size(), max_height = *max_element(A.begin(),A.end());
    vector<int> wood_at_level(max_height+1, 0);
    // at the end this vector will contain wood present at level [index]

    for(int i=0; i<n; i++)
        wood_at_level[A[i]-1]++;
        // currently it does not include wood from trees with height > A[i]
    int wood_collected = 0, curr_height = 0;
    for(int i=max_height-1; i>=0 and wood_collected<B; i--){
        wood_at_level[i] += wood_at_level[i+1];   // finding wood at level i (by including wood from trees with height > i+1)
        wood_collected += wood_at_level[i];     // adding wood collected from level max_height till level i
        curr_height = i;
    }
    return curr_height;
}
// level max_height will always have zero wood and will be the last/top level.

// level           Trees
// 4 (max_height)
// 3                        |
// 2                    |   |
// 1                |   |   |
// 0                |   |   |