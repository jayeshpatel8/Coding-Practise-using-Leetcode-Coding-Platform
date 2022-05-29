class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int N = nums.size(), ans = 0;
        vector<array<int,2>> st;
        st.push_back({0,0});
        for (int i=1; i<N; i++){
            int step = 0;
            while (!st.empty() && nums[st.back()[0]] <= nums[i]){
                step = max(step, st.back()[1] );
                st.pop_back();
            }
            if (st.empty())
                step = 0;
            else step++;
            st.push_back({i,step});
            ans= max(ans, step);
        }
        return ans;
    }
};