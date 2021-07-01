// https://www.interviewbit.com/problems/reverse-the-string/

string Solution::solve(string A) {
    string temp, s;
    int started = 0, noWord = 1;
    for(int i=A.length()-1; i>=0; i--){
        if(A[i] == ' '){
            if(started){
                reverse(temp.begin(), temp.end());
                if(noWord){
                    s = temp;
                    noWord = 0;
                }
                else
                    s = s + " " + temp;
                temp = "";
                started = 0;
            }
        }
        else{
            started = 1;
            temp.push_back(A[i]);
        }
    }
    if(started){	// if the last word is yet to be included
        reverse(temp.begin(), temp.end());
        if(noWord)
            s = temp;
        else
            s = s + " " + temp;
    }
    return s;
}
