class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        sort(begin(ranges), end(ranges));
        long ans=  1;
        int end=-1, mod  =1e9 + 7;
        
        
        for (int i=0,j=0 ;i<ranges.size(); i++){            
            
            if (end <ranges[i][0]){
                ans = (ans * 2)%mod;
            }
            end = max(end,ranges[i][1]);
        }
        return ans;
    }
};