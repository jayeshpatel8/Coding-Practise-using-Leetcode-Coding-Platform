class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans  =  0;
        for (auto i=0; i<nums.size();i++){
            int first= to_string(nums[i])[0] - '0';
            for (auto j=i+1; j< nums.size(); j++){
                ans += (gcd(first, nums[j] % 10) == 1);
            }
        }
        return ans;
    }
};