class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int mxsum = nums[0], misum=nums[0], total = 0;
        int cur=0, cur2=  0;
        for (auto i : nums){
            cur = max(cur +i , i);
            mxsum = max(mxsum, cur );
            cur2 = min(cur2 +i , i);
            misum = min(misum, cur2 );
            total +=i;
        }
        return mxsum <= 0 ? mxsum : (max(total - misum, mxsum));
    }
};