class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int f[2001]={};
        int ans=-1;
        for (auto i: nums){        
            if (f[-i + 1000]) 
                ans = max(ans,abs(i));
            
            f[i+1000]=1;
        }
        return ans;
    }
};
