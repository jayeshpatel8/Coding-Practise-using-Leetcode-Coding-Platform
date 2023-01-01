class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss (s);
        unordered_map<char,string> map;
        set<string> st;
        int i=0,N=pattern.size();
        for (string w; ss>>w;i++){
            if (i >= N) return false;
            auto ch = pattern[i];
            if (map.count(ch)){
                if (map[ch] != w) return false;
            }
            else if (st.count(w)) return false;
            else map[ch]=w,st.insert(w);
        }
        return (i>= N);
    }
};