class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n%2) return false;
        
        for (int i=0,  cnt=0; i<n; i++){
            if (s[i]=='(' || locked[i]=='0') cnt++;
            else cnt--;
            if (cnt < 0) return false;
        }
        for (int i=n-1,  cnt=0; i>=0; i--){
            if (s[i]==')' || locked[i]=='0') cnt++;
            else cnt--;
            if (cnt < 0) return false;
        }
        return true;
    }

};