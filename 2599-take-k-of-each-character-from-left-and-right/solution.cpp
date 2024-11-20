class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k==0) return 0;
        vector<int>  cnt(3);        
        for (int i=0; i<s.size(); i++)
            cnt[s[i]-'a']++;
        
        for (int j=0; j<3; j++) if (cnt[j] <k) return -1;        
        int ans= 0;
        for (int i=0, j=0; i<s.size(); i++){
            int idx = s[i]-'a';
            cnt[idx]--;
            while (j<=i && cnt[idx] < k){
                cnt[s[j++]-'a']++;
            }
            ans = max(ans,i-j+1);
        }
        return s.size() - ans;
    }
};
