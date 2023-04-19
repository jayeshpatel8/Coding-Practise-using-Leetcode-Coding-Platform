class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        for (int i=1; i<nums.size(); i++){
            auto sum  = nums[i]+nums[i-1];
            if (st.count(sum)) return true;
            st.insert(sum);
        }
        return false;
    }
};