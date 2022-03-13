class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m;
        m['[']=']';
        m['{']='}';
        m['(']=')';
        stack<char> st;
        for (int i=0; i<s.size();i++){
            auto it  = m.find(s[i]);
            if (it == m.end()){
                if (st.empty() || st.top() != s[i]) return false;
                st.pop();
            }
            else
                st.push(it->second);
        }
        return st.empty();
    }
};