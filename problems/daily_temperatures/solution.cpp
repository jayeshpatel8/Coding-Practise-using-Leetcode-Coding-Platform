class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> st  , ans (T.size());
        for (int i=0; i<T.size(); i++){
            while(!st.empty() && T[st.back()] < T[i]){
                int j = st.back(); st.pop_back();
                ans[j] = i-j;
            }
            st.push_back(i);
        } 
        return ans;
    }
};