class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26,100000), last(26);
        
        for (int i=0; i<s.size(); i++){
            int c = s[i]-'a';
            first[c] = min(first[c],i);
            last[c]=i;
        }
        int ans=0;
        for ( int i=0; i<26; i++){
            if (first[i]<last[i]){
                unordered_set<char> set(begin(s)+first[i]+1,begin(s) +last[i]);
                ans += set.size();
            }
        }
        return ans;          
    }
};
