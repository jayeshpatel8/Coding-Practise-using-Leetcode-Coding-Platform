class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st (begin(nums1),end(nums1));
        set<int> st2;
        for (auto i : nums2)
            if (st.count(i))
                st2.insert(i);
        return  vector<int> (begin(st2),end(st2));
    }
};