class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for (int i= 2; i<n-1; i++){
            if (!isPal(getstr(n,i))) return false;
        }
        return true;
    }
    bool isPal(string s){
        //string s =  to_string(i);
        for (int i=0, j=s.size()-1; i<j; i++,j--){
            if (s[i]!=s[j]) return false;
        }
        return true;
    }
    string getstr(int n, int b){
        string ans;
        while (n > 0){            
            ans.push_back(n%b);
            n = n/b;
        }
        return ans;
    }
};