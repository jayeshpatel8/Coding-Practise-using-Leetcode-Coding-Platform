class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int left = -1, minPos=-1, maxPos=-1;
        long long  ans = 0;

        for (int i = 0; i<nums.size(); i++){
            auto n = nums[i];
            if (n > maxK || n < minK) left = i;
            else{
                if (n == minK) minPos=i;
                if (n == maxK) maxPos=i;
            }
            ans += max(0,min(minPos, maxPos)-left);
        }
        return ans;
    }
};