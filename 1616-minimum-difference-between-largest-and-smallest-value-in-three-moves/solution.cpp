class Solution {
public:
    int minDifference(vector<int>& nums) {
        int N = nums.size();
        if (N <=4) return 0;
        int ans = INT_MAX;
        // Partially sort the first four elements
        partial_sort(nums.begin(), nums.begin() + 4, nums.end());
        // Find the 4th largest element
        nth_element(nums.begin() + 4, nums.begin() + (N - 4),
                    nums.end());
        // Sort the last four elements
        sort(nums.begin() + (N - 4), nums.end());
        for (int i=0, j=N-4; j<N; i++,j++){
            ans = min(ans, nums[j]- nums[i]);
        }
        return ans;
    }
};
