class Solution {
public:
    int minimumPushes(string word) {
        int f[26]={};
        for (auto c : word) f[c-'a']++;
        sort(rbegin(f), rend(f));
        int cnt=0, ans = 0;
        for (auto c : f){
            if (c <=0)break;
            ans += (cnt++ / 8 + 1 ) * c;
        }
        return ans;
    }
};
