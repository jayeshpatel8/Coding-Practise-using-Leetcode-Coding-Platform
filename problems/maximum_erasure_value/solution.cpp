class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> map(10001,-1);
        int sum=0, msum=0;
        int l=0;
        for (int i=0; i < nums.size(); i++){
            int n = nums[i];
            for (int prev=map[n]; l<=prev; l++){
                sum -= nums[l];
                map[nums[l]] = -1;
            }
            
                sum += n;
                map[n] = i;
                msum = max(sum,msum);
            
        }
        return max(sum,msum);
    }
};