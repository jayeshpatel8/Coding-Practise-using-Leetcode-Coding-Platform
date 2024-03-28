class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> f;
        int ans = 1;
        for (int i=0,j=0; i<nums.size(); i++){
            f[nums[i]]++;
            while (f[nums[i]] > k){
                f[nums[j++]]--;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};
