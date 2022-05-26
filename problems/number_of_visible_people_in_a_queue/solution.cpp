class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n),st;
        for (int i=n-1; i>=0; i--){
            int cnt = 0;
            while (!st.empty() && st.back() <= heights[i])
                cnt++, st.pop_back();
            ans[i] = cnt + !st.empty();
            st.push_back(heights[i]);
        }
        return ans;
    }
};