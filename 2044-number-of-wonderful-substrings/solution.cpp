class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        vector<int> cnt(1024);
        cnt[0]=1;
        int mask=0;
        
        for (auto c : word){
            mask ^= 1 << (c-'a');
            ans += cnt[mask];
            for (int m=1; m<1024; m<<=1){
                ans += cnt[mask ^ m];
            }
            cnt[mask]++;
        }
        return ans;
    }
};
