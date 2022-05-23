class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> map(10001),st,ans(nums1.size());
        
        for (int i=nums2.size()-1; i>=0; i--){
            while (!st.empty() && st.back() <= nums2[i])
                st.pop_back();
            map[nums2[i]] = st.empty()?-1:st.back();
            st.push_back(nums2[i]);
        }
        for (int i=0; i< nums1.size(); i++)
            ans[i] = map[nums1[i]];
        return ans;
    }
};