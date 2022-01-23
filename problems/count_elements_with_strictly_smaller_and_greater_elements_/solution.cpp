class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int ans = 0;
        for (int i =1,s=nums[0], n = nums.size(),e=nums[n-1]; i<n; i++){
            if (nums[i] > s && nums[i] < e)
                ans++;
        }
        return ans;
    }
};