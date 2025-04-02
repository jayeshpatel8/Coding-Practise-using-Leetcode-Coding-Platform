class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<long long> diff(nums.size());
        long long ans = 0;
        for (int i=0; i<nums.size(); i++){
            
            for (int j=i+1; j<nums.size(); j++){
                for ( int k=j+1; k<nums.size(); k++){
                    ans = max(ans, (nums[i] - nums[j])*(long long)nums[k]);        
                }
            }
        }
        return ans< 0? 0 : ans;
    }
};
