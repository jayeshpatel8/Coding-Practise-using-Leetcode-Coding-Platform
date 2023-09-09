class Solution {
    public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned int sum[1001]={};
        sum[0]=1;
        for  (int s=1; s<=target; s++){
            for (auto i: nums)
                if (s >= i)
                    sum[s] +=sum[s-i];
        }
        return sum[target];
    }
};