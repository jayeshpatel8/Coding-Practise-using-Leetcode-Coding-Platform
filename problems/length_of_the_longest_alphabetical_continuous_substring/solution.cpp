class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans =  1;
        for (int i=1,j=1; i<s.size(); i++){
            
            if (s[i]  ==s[i-1] + 1){
                j++;
                ans =max(ans, j);
            }
            else
                j=1;
        }
        return ans;
    }
};