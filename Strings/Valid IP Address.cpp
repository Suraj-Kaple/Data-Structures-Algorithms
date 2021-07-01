// https://www.interviewbit.com/problems/valid-ip-addresses/

int getNum(string A){		// convert string to number
    int n = A.length(), num = 0;
    for(int i=0; i<n; i++){
        num *= 10;
        num += (A[i] - '0');
    }
    return num;
}

bool isValid(int a, string A){		// is the number valid
    if(A[0] == '0' and A.length() != 1)
        return false;
    if(0 <= a and a <= 255)
        return true;
    return false;
}

vector<string> Solution::restoreIpAddresses(string s) {
    int n = s.length();
    vector<string> ans;
    if(!(4 <= n and n <= 12)) return ans;

    int a, b, c, d;
    for(int i=1; i<n-2 and i<=3; i++){
        string A = s.substr(0,i);
        if(!isValid(getNum(A), A))
            continue;
        for(int j=i+1; j<n-1 and j-i<=3; j++){
            string B = s.substr(i,j-i);
            if(!isValid(getNum(B), B))
                continue;
            for(int k=j+1; k<n and k-j<=3; k++){
                string C = s.substr(j,k-j);
                string D = s.substr(k,n);
                if(!(isValid(getNum(C), C) and isValid(getNum(D), D)))
                    continue;
                ans.push_back(A + "." + B + "." + C + "." + D);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
// Main Idea: You need to place only 3 dots and every segment should be a valid one.