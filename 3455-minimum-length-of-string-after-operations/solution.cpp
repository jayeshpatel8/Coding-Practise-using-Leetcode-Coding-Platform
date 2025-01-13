class Solution {
public:
    int minimumLength(string s) {
        int cnt[26]={};
        for (auto i : s) cnt[i-'a']++;
        int ans = 0;
        for (auto i : cnt){
            if (i > 0){
                ans  += (i %2 == 0 )+ 1;
            }
        }
        return ans;
    }
};
