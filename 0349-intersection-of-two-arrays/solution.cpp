class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st (begin(nums1),end(nums1));
        vector<int> ans;
        for (auto i : nums2)
            if (st.count(i))
                ans.push_back(i), st.erase(i);
        return  ans;
    }
};
