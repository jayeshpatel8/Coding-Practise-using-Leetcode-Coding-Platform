class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;
        
        for (int i=0,j=0; i <s.size(); i++){
            maxCost -= abs(s[i]-t[i]);
            while ( maxCost <0 )
                maxCost +=abs(s[j]-t[j++]);
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};