class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int f[101]={};
        int  m = 0,ans=0;
        for (auto i : nums) m = max(m, ++f[i]);
        
        
        for (auto i : f) if (i==m) ans +=i;
        return ans;
    }
};
