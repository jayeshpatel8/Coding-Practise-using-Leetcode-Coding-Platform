class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int ans = 0;
        for (int i=0, j=nums.size()-1; i<j; ){
            int sum = nums[i] + nums[j];
            if (sum == k)
                ans++,i++,j--;
            else if (sum < k ){
                i++;            
            }
            else  j--;
        }
        return ans;
    }
};