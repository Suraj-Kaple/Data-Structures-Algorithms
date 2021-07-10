// https://www.interviewbit.com/problems/edit-distance/

int Solution::minDistance(string A, string B) {
    int n=A.length(), m=B.length();
    vector<vector<int> > opr(n+1, vector<int> (m+1));
    // rows are for A, cols are for B
    // opr[i][j] tells minimum #operation required to convert A[0...i-1] to B[0...j-1]

    // tabulate
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(!i and !j)   opr[i][j] = 0;  // opr[0][0]=0
            else if(!i or !j)   opr[i][j] = max(i,j);   // opr[0][j]=j and opr[i][0]=i
            else if(A[i-1] == B[j-1]){  // if last elements are equal in A[0...i-1] to B[0...j-1]
                opr[i][j] = opr[i-1][j-1];
            }
            else{
                opr[i][j] = min(min(opr[i-1][j], opr[i][j-1]), opr[i-1][j-1]) + 1;  // adding 1 for operation mentioned below
            }
        }
    }

    // print dp table
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m; j++){
    //         cout<<opr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return opr[n][m];
}

// what adding 1 means?
// if X = opr[i-1][j] is minimum, it implies remove last element of A
// if Y = opr[i][j-1] is minimum, it implies insert at end of A
// if Z = opr[i-1][j-1] is minimum, it implies replace last element of A by last element of B

// alternate way
// without A[i-1] == B[i-1]
// opr[i][j] = min(min(opr[i-1][j], opr[i][j-1]) + 1, opr[i-1][j-1] + cost(i,j));
// i.e. opr[i][j] = min(X+1, Y+1, Z+cost(i,j))
// where cost(i,j) = 0  if A[i-1]==B[i-1]
//                   1  if A[i-1]!=B[i-1] 