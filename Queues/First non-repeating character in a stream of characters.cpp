// https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/

string Solution::solve(string A) {
    int n=A.size();
    string ans;
    vector<int> hash(26,0);
    queue<char> q;

    ans.push_back(A[0]);
    q.push(A[0]);
    hash[A[0] - 'a']++;
    for(int i=1; i<n; i++){
        hash[A[i] -'a']++;

        if(q.front() == A[i]){
            while(!q.empty() and hash[q.front() - 'a'] > 1)
                q.pop();
        }
        else{
            if(hash[A[i]-'a'] == 1)
                q.push(A[i]);
        }
        if(!q.empty())  ans.push_back(q.front());
        else ans.push_back('#');
    }
    return ans;
}

// queue[front] stores the first non-repeating character
// hash stores frequency of lowercase alpahabets
// add to queue only if frequency is == 1
// keep popping till frequency of front is > 1 and q is not empty