class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<string> w[17];
        vector<int> dp[17];
        for (auto &s : words)
            w[s.size()].push_back(s);
        unordered_map<string,int> map;
        int ans = 1;
        for (int i=16; i>0; i--){
            if (w[i].size()){
                for (int j=0; j<w[i].size(); j++){
                    dp[i].push_back(1);
                    if (i==16) continue;
                    for (int k=0; k<w[i+1].size(); k++){
                        if (isvalid(w[i][j], w[i+1][k], i+1))
                            dp[i][j] = max(dp[i][j], 1 + dp[i+1][k]);
                    }
                    ans= max(ans, dp[i][j]);
                }                
            }
        }
        return ans;
    }
    bool isvalid(string &s1, string &s2, int len){
        int changed=0;
        for (int i=0,j=0; j<len; j++){
            if (s1[i] == s2[j]) i++;
            else if (changed){
                return false;
            }
            else
                changed = 1;
        }
        return true;
    }
};