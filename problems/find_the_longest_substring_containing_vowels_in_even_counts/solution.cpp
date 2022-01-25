class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        vector<int> f(1<<5,-2);
        char arr[26]={};        
        string v = "aeiou";
        int  j = 0, ans = 0;
        for (auto c : v) arr[c-'a']=(1<<j++);
        f[0]=-1;
        for (int i = 0, p = 0; i<s.size(); i++){
            int c = s[i]-'a';
            p ^= ((arr[c]));
            if (f[p] != -2) ans = max(ans, i-f[p]);
            else
                f[p]=i;
        }
        return ans;
        /*
        for (int l=n; l>=1; l--){
            for ( int i=0; i+l-1<n; i++){
                if ((f[i+l] ^ f[i])==0) {
                    return l;
                }                
            }
        }*/
        return 0;
    }
};