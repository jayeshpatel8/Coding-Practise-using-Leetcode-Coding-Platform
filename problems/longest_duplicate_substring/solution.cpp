class Solution {
public:
    string longestDupSubstring(string s) {
        int l=1, r=s.size();
        const long long d = 27,   mod=100000000019;
        int ans;
        while(l<=r){
            int m  = ( l + r ) >> 1;
            unsigned long long found = 0, hash=0,d0=1;
            unordered_set<unsigned long long> sh;

            for (int i=0; i<= s.size(); i++){
                hash = ((hash * d) + s[i]);//%mod;
                
                if (i >= m)
                    hash = hash   - d0 * s[i-m];// % mod) %mod;
                else
                    d0 =(d0 *  d );// % mod;
                if (i>=m-1) {
                    if (sh.count(hash)){
                        found=1;  
                        ans = i+1-m;
                        break;
                    }
                    sh.insert(hash);
                }
            }
            
            if (found)
                l= m + 1 ;
            else
                r = m - 1;
            
        }
        return s.substr(ans,l-1);
    }
};