// https://www.geeksforgeeks.org/maximize-array-sun-after-k-negation-operations/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int _;
    cin>>_;
    while(_--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        
        sort(a.begin(), a.end());
        int idx = 0;
        while(k-- and idx<n){
            if(a[idx] < 0){
                a[idx] *= (-1);
                idx++;
            }
            else if(a[idx] == 0)
                break;
            else{
                if(!(k%2)){
                    auto itr = min_element(a.begin(),a.end());
                    *itr = (-1) * (*itr);
                }
                break;
            }
        }
        if(idx == n){
            if(!(k%2)){
                auto itr = min_element(a.begin(),a.end());
                *itr = (-1) * (*itr);
            }
        }
        int summ = 0;
        for(int i=0; i<n; i++){
            summ += a[i];
        }
        cout<<summ<<endl;
    }
    return 0;
}