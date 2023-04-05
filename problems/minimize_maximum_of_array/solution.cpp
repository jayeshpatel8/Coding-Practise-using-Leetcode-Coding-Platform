class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long ans = 0 ,psum = 0;
        for (int i=0; i<nums.size();i++){
            psum += nums[i];
            ans = max(ans, (psum +i)/ (i+1));
        }
        return ans;
    }
};