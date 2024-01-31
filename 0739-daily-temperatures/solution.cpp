class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> st, ans(t.size());

        for (int i = 0; i<t.size(); i++){
            while(!st.empty() && t[st.back()] < t[i]){
                int j = st.back();st.pop_back();
                ans[j] = i-j;
            }
            st.push_back(i);
        }   
        return ans;
    }
};
