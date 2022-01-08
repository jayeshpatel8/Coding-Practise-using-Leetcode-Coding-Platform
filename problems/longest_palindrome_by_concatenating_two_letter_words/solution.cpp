class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> m;
        vector<string> s;
        string r;
        int ans=0;
        for (auto &w  : words){
            m[w]++;
        }
            bool same=false;
        for (auto& [s,c] : m){
            
            if (s[0]==s[1]){
                ans +=  (c/2)*4;
                c -=(c/2)*2;
                same |= c;
            }
            else{
                string r;
                r+=s[1]; r+=s[0];
                if (m.count(r)){
                    ans += min(c,m[r])*4;
                    m.erase(r);
                }
            }
        }
        return ans+(same * 2);
    }
};