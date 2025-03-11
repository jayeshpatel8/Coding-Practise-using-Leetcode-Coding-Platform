class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0 ,cnt[3]={-1,-1,-1};
        
        for (int j=0; j<s.size(); j++){
            cnt[s[j]-'a']=j;
            ans += 1 + min({cnt[0],cnt[1],cnt[2]});
        }
        return ans;
    }
};
