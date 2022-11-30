class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        for (int i=0; i<arr.size(); i++){
            map[arr[i]]++;
        }
        unordered_set<int> st;
        for (auto &[k,v] : map){
            if (st.count(v)) return false;
            st.insert(v);
        }
        return true;
    }
};