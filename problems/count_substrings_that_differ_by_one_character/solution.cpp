class Solution {
public:
    int countSubstrings(string s, string t) {
        int sn = s.size(), tn = t.size(), ans = 0;
        vector<vector<int>> match(sn+1,vector<int>(tn+1));
        
        for (int i = 0; i<sn; i++){            
            for (int j = 0; j<tn; j++){
                int f=0;
                for (int l=0, lm = min(sn-i,tn-j); l<lm; l++){
                    if (s[i+l] == t[j+l] ) {
                        if (f==1) ans++;
                     }
                    else if (f++) break;
                    else
                        ans++;
                }
            }
        }
        return ans;
    }
};