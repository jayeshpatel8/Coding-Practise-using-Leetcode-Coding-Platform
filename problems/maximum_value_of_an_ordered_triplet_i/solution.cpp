class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int maxi=0, maxdiff=0;
        for (auto i : nums){
            ans= max(ans, 1LL * maxdiff * i);
            maxdiff = max(maxdiff, maxi  - i);
            maxi = max(maxi,i);
        }
        return ans;
    }
};