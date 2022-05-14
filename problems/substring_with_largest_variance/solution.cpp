class Solution {
public:
    int largestVariance(string s) {
        int n = s.size(), ans = 0;
        vector<int> f(26);
        vector<vector<int>> freq(n+1,vector<int>(26));
        for (int i=0; i<n; i++){
            auto c  = (s[i]-='a');
            ++f[c];
            freq[i+1] = f;
        }
        for (int c1 = 0; c1<26; c1++){
            for (int c2=0; c2<26; c2++){
                if (c1 == c2 || freq[n][c1]==0 || freq[n][c2]==0) continue;
                int ct1=0,ct2=0;
                for (int i=0; i<n; i++){                    
                    auto c = s[i] ;
                   
                    if (c == c1 )ct1++;
                    else if (c == c2 ) ct2++;
                    if (ct2 && ct1 > ct2)
                        ans= max(ans, ct1-ct2);
                    if (ct1 < ct2 && freq[n][c2]-freq[i+1][c2]!=0)
                        ct1=ct2=0;                    
                        
                }
            }
            
        }
        return ans;
    }
};