class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> st;
        int j = INT_MIN ;
        for (int i=nums.size()-1,sz=0; i>=0; i--){
            auto n = nums[i];
            if (j > n) return true;
            while (sz && n > st.back()) j=st.back(), st.pop_back(),sz--;
            st.push_back(n);
            sz++;
        }
        return false;
    }
};