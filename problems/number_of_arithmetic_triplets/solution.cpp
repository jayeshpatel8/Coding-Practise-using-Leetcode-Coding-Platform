class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> st(begin(nums),end(nums));
        int  ans = 0;
        for (auto i : nums){
            if (st.count(-diff + i) && st.count(diff+i)) ans++;
        }
        return ans;
    }
};