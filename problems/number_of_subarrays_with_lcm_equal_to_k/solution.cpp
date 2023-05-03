class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int ans = 0;
        for (int i=0; i<nums.size(); i++){
            int d = 1;
            for (int j=i; j<nums.size() ; j++){
                d= lcm(d,nums[j]);
                ans += d==k;
                if (d>k)break;
            }
        }
        return ans;
    }
};