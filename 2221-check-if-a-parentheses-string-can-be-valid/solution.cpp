class Solution {    
public:
    bool canBeValid(string s, string locked) {
        int cnt=0;
        if (s.size() & 1) return false;
        for (int i=0; i<s.size(); i++){
            if (s[i] == '(' || locked[i] == '0') cnt++;
            else{
                cnt--;
            }
            if (cnt < 0) return false;
        }
        cnt=0;
        for (int i=s.size()-1; i>=0; i--){
            if (s[i] == ')'|| locked[i] == '0') cnt++;
            else{
                cnt--;
            }
            if (cnt < 0) return false;
        }
        return true;
    }
};
