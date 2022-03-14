class Solution {
public:
    string simplifyPath(string path) {
        string tmp,ans;
        vector<string> st;
        stringstream ss(path);
        
        while (getline(ss, tmp,'/')){
            if (tmp.empty() || tmp == ".") continue;
            if (tmp == ".."){
                if (!st.empty()) st.pop_back();
            }
            else
                st.push_back(tmp);
        }
        for (auto &s  : st) ans += '/' + s;
        
        return ans.empty()? "/" : ans;
    }
};