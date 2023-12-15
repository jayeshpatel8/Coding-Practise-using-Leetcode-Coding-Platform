class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> st;
        for (auto& s : paths){
            st[(s[0])] |= 1;
            st[(s[1])] |= 2;
        }
        for (auto &[k,v] : st){
            if (v==2) return k;
        }
        return "";
    }
};
