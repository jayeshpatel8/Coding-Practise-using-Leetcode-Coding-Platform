class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0 ,f[256]={};
        for (int j =0, i=0; i<s.size(); i++){
            while (f[s[i]])
                f[s[j++]]--;
            ans = max(i-j+1,ans);            
            f[s[i]]++;
        }
        return ans;
    }
};