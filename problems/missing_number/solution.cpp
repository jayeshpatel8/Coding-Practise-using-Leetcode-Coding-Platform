class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums),0);
        int  n = nums.size();
        return (n*(n+1)/2) - sum;
    }
};