class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mxsum =INT_MIN, misum=INT_MAX  , sum=0 , csum=0;
        for (auto i : nums){
            sum = max(sum+i,0);
            mxsum = max(mxsum,sum);
            csum = min(csum+i,0);
            misum = min(misum,csum);            
        }
        return max(mxsum, abs(misum));
    }
};