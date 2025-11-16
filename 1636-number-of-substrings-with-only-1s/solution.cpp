class Solution {
public:
    int numSub(string s) {
        int mod = 1e9 + 7, ans = 0,cnt = 0;
        
        for (auto c : s){
            if (c == '1')
                ans = (ans + ++cnt)%mod;
            else
                cnt = 0;
        }
        return ans;
    }
};
