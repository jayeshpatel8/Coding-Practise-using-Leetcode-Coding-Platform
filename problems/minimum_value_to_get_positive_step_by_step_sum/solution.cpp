class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans= 1, sum = 1;
        
        for (auto i : nums){
            sum = sum + i;
            if (sum <1){
                ans += abs(sum) + 1;
                sum = 1;
            }
        }
        return ans;
    }
};