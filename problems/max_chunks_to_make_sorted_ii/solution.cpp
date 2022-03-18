class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> st;
        for (auto &i : arr){
            int curmax=i;
            while(!st.empty() && i < st.back() ){
                curmax = max(curmax,st.back());
                st.pop_back();
            }
            st.push_back(curmax);
        }
        return st.size();
    }
};