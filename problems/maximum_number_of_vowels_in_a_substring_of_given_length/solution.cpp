class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        int vow[26]={1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0};
        for (int i=0,j=0 ,cnt = 0; i<s.size(); i++){
            cnt+=vow[s[i]-'a'];
            if (i >= k)
                cnt-=vow[s[j++]-'a'];
            ans= max(ans, cnt);
        }
        return ans;
    }
};