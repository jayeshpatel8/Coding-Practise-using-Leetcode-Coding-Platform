class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int  n  = nums.size();
        vector<int> st;
        long long mi=0,ma=0;
        
        for (int i=0; i<=n; i++){
            while (!st.empty() &&(i==n || nums[st.back()] > nums[i]))
            {
                int j = st.back(), k = st.size() <2 ? -1 : st[st.size()-2];
                mi += (i-j) * (j-k) * (long long)nums[j];
                st.pop_back();
            }
            st.push_back(i);
        }
        st.clear();
        for (int i=0; i<=n; i++){
            while (!st.empty() &&(i==n || nums[st.back()] < nums[i]))
            {
                int j = st.back(), k = st.size() <2 ? -1 : st[st.size()-2];
                ma += (i-j) * (j-k) * (long long)nums[j];
                st.pop_back();
            }
            st.push_back(i);
        }
        return ma-mi;
    }
};