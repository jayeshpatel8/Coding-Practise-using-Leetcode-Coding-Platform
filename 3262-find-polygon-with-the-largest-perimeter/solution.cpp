class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans = -1 , sum=0;
        sort(begin(nums), end(nums));
        
         
        for(int i=0;i<nums.size();i++){
            if(nums[i]<sum)ans = nums[i] + sum;
            sum+=nums[i];
        }
        return  ans;
    }
};
