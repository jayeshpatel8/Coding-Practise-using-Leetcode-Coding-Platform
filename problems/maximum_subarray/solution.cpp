class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long sum=INT_MIN,cur=INT_MIN;
        for (auto i : nums){
            cur = max<long>(cur + i, i);
            sum = max(sum, cur);
        }
        return sum;
    }
};