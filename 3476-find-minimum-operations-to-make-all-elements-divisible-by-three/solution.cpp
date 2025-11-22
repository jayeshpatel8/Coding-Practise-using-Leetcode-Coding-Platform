class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (auto i : nums){
            if ( i==1) ans++;
            else ans += (i%3) != 0;
        }
        return ans;
    }
};
