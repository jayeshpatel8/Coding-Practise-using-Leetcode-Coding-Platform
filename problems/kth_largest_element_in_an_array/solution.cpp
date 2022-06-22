class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int i;
        for (i=nums.size()-1; k>1; i--){
            k--;
        }
        return nums[i];
    }
};