class Solution {
public:
    bool areOccurrencesEqual(string s) {
        
        int freq[128]={};
        for ( auto c : s) freq[c]++;
        for ( int i=1; i<s.size(); i++) 
            if (freq[s[i]] != freq[s[i-1]]) 
                return false;
        return true;
    }
};