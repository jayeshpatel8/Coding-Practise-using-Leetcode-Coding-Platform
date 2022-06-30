class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int N = nums.size() ,ans = 0;
        sort(begin(nums), end(nums));
        for (int i=0, j=N-1; i<j; i++,j--)
            ans += nums[j]-nums[i];
        return ans;
    }
};