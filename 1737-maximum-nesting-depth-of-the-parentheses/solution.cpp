class Solution {
public:
    int maxDepth(string s) {
        int cnt=0, ans  = 0;
        for (auto c : s){
            if (c =='(') cnt++;
            else if (c == ')') ans = max(ans , cnt--);            
        }
        return ans;
    }
};
