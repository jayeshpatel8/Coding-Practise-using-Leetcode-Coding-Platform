class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        string s1 = "[({";
        unordered_map<char,char> bra={{']','['},{')','('}, {'}','{'}};
        for (auto c :s){
            if (s1.find(c) != string::npos)
                st.push(c);
            else{
                if (st.empty() || st.top() != bra[c] ) return false;
                st.pop();
            }
        }
     return st.empty();   
    }
};