class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans = LONG_MAX;
        int l=1, r= 1e6;
        while (l<r){
            long long c1 = 0 ,c2=0;
            long long m  = (l+r)/2;
            for (auto i =0; i< nums.size(); i++){
                c1 += (long long)abs(m -nums[i]) * cost[i];
                c2 += (long long)abs(m +1-nums[i]) * cost[i];
            }
            ans= min(c1,c2);
            if (c1 < c2 )
                r=m; 
            else
                l=m+1;
        }
        return ans;
    }
};