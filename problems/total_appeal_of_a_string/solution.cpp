class Solution {
public:
    long long appealSum(string s) {
        long long ans = 0;
        
        int n= s.size();
        vector<int> idx(26,-1);
        for (int i=0, cur=0; i<n; i++){
            //abcab
            auto c = s[i]-'a';
            cur += i - idx[c];
            ans += cur;
            idx[c]=i;
        }
        return ans;
    }
};