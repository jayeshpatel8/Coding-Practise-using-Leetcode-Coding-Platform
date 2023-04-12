class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> st;
        for (auto i : nums) if (i) st.insert(i);
        return st.size();
    }
};