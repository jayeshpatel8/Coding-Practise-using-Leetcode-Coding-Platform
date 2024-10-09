class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0 , ans = 0;
        for (auto c : s){
            if (c =='(')  cnt++;
            else 
                cnt > 0 ? cnt-- :  ans++;
        }
        return cnt + ans;
    }
};
