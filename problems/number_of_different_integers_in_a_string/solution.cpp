class Solution {
public:
    int numDifferentIntegers(string s) {
        int n = s.size();
        unordered_set<int> ans;
        for (int i=0; i<n; ){
            while(i<n  && s[i]>='a' && s[i]<='z' ) i++;
            if (i==n) break;
            uint64_t d=0;
            while(i<n  && s[i]>='0' && s[i]<='9' ) {
                d   = d*10  + s[i]-'0'; 
                i++;
            }
            ans.insert(d);
        }
        return ans.size();
    }
};