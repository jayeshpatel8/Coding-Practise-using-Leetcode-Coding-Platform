class Solution {
public:
    long long appealSum(string s) {
        
        int n = s.size();
        long long ans = 0;
        vector<int> substr_cnt(26);
        for (int i=0,cnt=0; i<n; i++){
            cnt += i+1 - substr_cnt[s[i]-'a'];
            ans +=cnt;
            substr_cnt[s[i]-'a'] = i+1;
        }
        return ans;
    }
};