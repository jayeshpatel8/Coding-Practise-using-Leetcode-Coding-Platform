class Solution {
public:
    int longestSubstring(string s, int k) {
        int freq[26] = {};
        int max_unique=0 ,ans = 0;
        for (auto c : s) 
            if (0 == freq[c-'a']) 
                max_unique++, freq[c-'a']=1;
        for (int unique=1; unique <=max_unique; unique++){
            int u=0;
            int freq[26] = {},K=0;
            for (int i=0,j=0; i<s.size(); i++){
                if (freq[s[i]-'a']++==0) u++;
                if (freq[s[i]-'a'] == k) K++;
                while (u > unique){
                    if (freq[s[j]-'a'] == k) K--;
                    if (freq[s[j++] -'a']-- == 1 )u--;
                    
                }
                if (K==unique)
                    ans = max(ans, i-j+1);
            }
        }
        return ans;
    }
};