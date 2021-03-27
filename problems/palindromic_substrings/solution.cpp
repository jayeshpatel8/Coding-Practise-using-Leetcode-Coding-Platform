class Solution {
public:
    int countSubstrings(string s) {
        int n =  s.length();
        uint64_t cnt=0;

        for (int i=0; i<n; i++) {            
            // even 
            for (int start=i,end=i; start>=0 && end<n && s[start]==s[end]; start--,end++) 
                cnt++;
            // odd
            for (int start=i-1,end=i; start>=0 && end<n && s[start]==s[end]; start--,end++) 
                cnt++;
        }
        return cnt;
    }
};