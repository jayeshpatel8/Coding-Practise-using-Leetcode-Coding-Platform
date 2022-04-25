class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m[128]={}, i=0,j=0 ,ans = 0;
        for (; i<s.size(); i++){            
            if(m[s[i]]++ == 0 )
                ans = max(ans, i-j+1);
            else{
                while (m[s[i]] > 1) 
                    m[s[j++]]--;
            }
            
        }
        return ans;
    }
};