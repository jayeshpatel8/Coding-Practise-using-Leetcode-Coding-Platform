class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> v(26);
        iota(begin(v),end(v),1);
        for (int i = 0 ; i< chars.size(); i++){
            v[chars[i]-'a'] = vals[i];
        }
        int ans = 0 ,sum = 0;
        for (auto c : s){
            sum = max(0, sum + v[c-'a']);
            ans= max(ans, sum);
        }
        return ans;
    }
};