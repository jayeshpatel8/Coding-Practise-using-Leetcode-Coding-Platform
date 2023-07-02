class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] & 1 || nums[i] > threshold) continue;
            int len=1;
            for (int j=i+1;j<nums.size(); j++){
                if ((nums[j] & 1) == (nums[j-1] & 1) || nums[j] > threshold) break;
                len++;
            }
            ans= max(ans, len);
        }
        return ans;
    }
};