class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long sum= accumulate(begin(nums), end(nums),0L), sum1=0;
        int ans=0;
        for ( int i=0; i<nums.size()-1; i++){
            sum1 += nums[i]; sum-=nums[i];
            ans += sum1>=sum;
        }
        return ans;
    }
};
