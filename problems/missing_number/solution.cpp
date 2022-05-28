class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int  n = nums.size();
        for (int i=0; i<n; i++){
            int idx = nums[i] > 1e4 ? nums[i] - 1e4 - 1 : nums[i];
            if (idx <n )
                nums[idx] = nums[idx] + 1e4 + 1;
        }

        for (int i=0; i<n; i++)
            if (nums[i] <= 1e4) return i;
        
        return n;
    }
};