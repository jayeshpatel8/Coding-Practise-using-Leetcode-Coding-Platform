class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int  n =  s.size();
        vector<int> freq;
        for (int i=1; i<=n/2; i++) if (s[0]==s[i]) freq.push_back(i);
        for (auto k : freq){
            if (n % (k)) continue;
            int i=0,j=k;
            for (; j<n; j++,i++){
                if (s[i] != s[j])break;
            }
            if (j==n) return true;
        }
        return false;
    }
};