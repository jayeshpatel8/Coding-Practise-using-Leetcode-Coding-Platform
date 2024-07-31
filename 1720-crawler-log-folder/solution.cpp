class Solution {
public:
    int minOperations(vector<string>& logs) {
        vector<string> st;
        for (auto s : logs){
            if (s == "./") continue;
            else if (s == "../"){
                if (!st.empty())
                    st.pop_back();
            }else st.push_back(s);
        }
        return st.size();
    }
};
