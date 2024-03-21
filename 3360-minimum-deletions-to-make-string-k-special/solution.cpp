class Solution {
public:
    int minimumDeletions(string word, int k) {
        int f[26] ={};
        for (auto c : word) f[c-'a']++;
        int ans = INT_MAX;
        
        for (char c = 0; c <26; c++){
            int cnt = f[c];
            if (cnt ){
                int a=0;
                for (auto c : f) 
                    if (c < cnt) 
                     a += c;
                     else if ( c > cnt + k) a += c - cnt-k; 
                
                ans= min(ans, a);
            }
        }
        return ans;
    }
};
