class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        for (int c='A'; c<='Z';c++){
            
            for (int i=0,j=0,k1=0; i<s.size(); i++){
                if (s[i]!=c){
                    k1++;
                    while (k1>k) k1-=s[j++]!=c;
                }
                ans = max(ans, i-j+1);
            }            
        }
        return ans;
    }
};