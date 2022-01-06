class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set<int> s;
        int n  = text.size();

        int mod=1e9 + 7;
        for ( int k=1; k<n; k++){            
             long long h_r=0, h_l=0, base=1;
            for (int r=k, l=k-1; l >= 0 && r < n; --l,r++){
                h_r = (h_r * 29 + text[r]) % mod;
                h_l = (h_l + text[l] * base) % mod;
                base= (base * 29)%mod;
                if ( h_r == h_l)
                    s.insert(h_l);
            }
        }
        return s.size();
    }  
};

