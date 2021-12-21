class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        
        for ( int i =0; i<nums.size()-1; i++){
            int s = min(nums[i],nums[i+1]), l = max(nums[i],nums[i+1]);
            ans += l - s;
            for (int j=i+2; j<nums.size(); j++){
                s = min(nums[j],s), l = max(nums[j],l);
                ans += l - s;
            }
        }
        return ans;
    }
};