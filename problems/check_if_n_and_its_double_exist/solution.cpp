class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        for (auto i : arr){
            if ( st.count(i * 2)) return 1;
            if ((i&1) == 0 && st.count(i/2))return 1;
            st.insert(i);
        }
        return 0;
    }
};