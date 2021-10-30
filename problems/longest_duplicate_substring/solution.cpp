class Solution {
public:
    int start=0 , mod = 100000000019;
    const long long d = 27;
    string longestDupSubstring(string s) {
        int l=1 , r = s.size(),len=0;
        
        while(l <= r){
            int m = ( l + r ) / 2;
            if (isDupSub(s,m)){
                l = m + 1;
                len = m;                
            }
            else 
                r = m - 1;
        }
        return s.substr(start,len);
    }
    bool isDupSub(string & s, int m){
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
                        start = i+1-m;
                        return true;
                    }
                    sh.insert(hash);
                }
            }
        return false;
    }  
};