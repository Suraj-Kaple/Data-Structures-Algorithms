// https://www.geeksforgeeks.org/greedy-algorithm-egyptian-fraction/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int nr, dr;
        cin>>nr>>dr;
        
        vector<int> drs;
        while(nr != 0){
            float denom = (float)dr/nr;
            int x = (int)ceil(denom);
            nr = nr*x - dr;
            dr = dr*x;
            cout<<"1/"<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// If dr/nr would have been an int, then this implies that nr is a common factor of dr and nr and now we got a fraction of the form 1/x.

// So for a moment consider instead of dr we have smallest multiple of nr greater than or equal to dr. Lets say it is M.
// Let the new numnber be Y = nr/M (which reduces to 1/x). Our original number is nr/dr.
// We have dr to be less than or equal to M which means nr/dr >= Y. So, we can take out 1/x from nr/dr.
// Now we are left with another fraction equal to nr/dr - 1/x = (nr*x - dr)/(dr * x)
// Repeat same procedure for this fraction till the fraction exhausts (or simply till nr != 0)
