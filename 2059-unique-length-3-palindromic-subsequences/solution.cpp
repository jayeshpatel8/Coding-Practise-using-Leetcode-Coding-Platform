class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<vector<int>> f(n+2,vector<int>(26));
        vector<pair<int,int>> idx(26, {n+1,-1});
        for (int i=0; i<n; i++){
            f[i+1] = f[i];
            auto ch  =  s[i]-'a';
            f[i+1][ch]++;
            idx[ch].first=min(i,idx[ch].first);
            idx[ch].second=i;
        }
        int ans = 0;
        for (int i=0; i<26; i++){
            auto [x,y]  =idx[i];
            if (x<y){
                auto &a = f[x+1], &b = f[y];
                for (int j=0; j<26; j++){
                    if (b[j] - a[j])  ans++;
                }
            }
        }
        return ans;
    }
};
