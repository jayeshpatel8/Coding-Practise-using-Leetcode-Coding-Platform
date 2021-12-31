class Solution {
public:
    
    int maxHeight(vector<vector<int>>& cubs) {
        for (auto& i : cubs) sort(begin(i),end(i));  //constraint : You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.
        cubs.push_back({0,0,0});
        sort(begin(cubs),end(cubs));
        
        int ans=0;
        vector<int> dp(cubs.size());
        for (int i=1; i<cubs.size(); i++){
            //constraint : You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj.
            int s = cubs[i][0], m= cubs[i][1], l = cubs[i][2]; //smallest, mid, largeest            
            for (int j=0; j<i; j++){
                if (cubs[j][0] <= s && cubs[j][1] <= m && cubs[j][2]<= l) 
                    dp[i] = max(dp[i],l + dp[j]);                
            }
            ans= max(ans, dp[i]);
        }
        return ans;
    }

};