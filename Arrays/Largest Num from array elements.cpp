// https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/

#include <bits/stdc++.h>
using namespace std;

bool criteria(int x, int y){
    string X = to_string(x), Y = to_string(y);
    int xlen = X.length(), ylen = Y.length(), i;
    
    for(i=0; i<xlen and i<ylen; i++){
        if(X[i] != Y[i]){
            return X[i]-'0' > Y[i]-'0';
        }
    }
    if(i >= xlen and i< ylen){
        int idx = 0;
        while(i<ylen and Y[i]-'0' == Y[idx] - '0'){
            i++; idx++;
        }
        if(i==ylen) return true;
        return Y[idx]-'0' > Y[i]-'0';
    }
    else if(i >= ylen and i< xlen){
        int idx = 0;
        while(i<xlen and X[i]-'0' == X[idx] - '0'){
            i++; idx++;
        }
        if(i==xlen) return true;
        return X[idx]-'0' < X[i]-'0';
    }
    return true;
}

bool criteria2(int x, int y){
    string X = to_string(x), Y = to_string(y);
    string XY=X + Y, YX = Y + X;
    return XY > YX;
}

int main (){
    vector<int> a = {54, 546, 548, 54, 60, 69, 6};
    sort(a.begin(), a.end(), criteria2);
    for(auto x:a)
        cout<<x<<" ";
    return 0;
}
