class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;        
        for (int i=0,j=0; i<nums.size();i++){
            if (nums[i])
                j=i+1;
            ans += i-j+1;
        }
        return ans;
    }
};
