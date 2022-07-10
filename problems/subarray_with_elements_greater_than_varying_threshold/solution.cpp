class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        vector<int> st;
        nums.push_back(0);
        for (int i = 0; i < nums.size(); ++i) {

            while (!st.empty() && nums[st.back()] > nums[i]) {
                int n = nums[st.back()]; st.pop_back();
                int j =  st.empty() ? -1 : st.back();
                
                if (n > threshold / (i-j-1)){
                    return i-j-1;
                }
            }

            st.push_back(i);
        }
        return -1;
    }
};