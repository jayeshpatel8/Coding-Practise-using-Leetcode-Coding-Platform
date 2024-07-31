class Solution {
public:
    string reverseParentheses(string s1) {
        string ans;
        string s = s1 ;
        vector<int> st;
        for (int i=0; i<s.size();i++){
            if (s[i] == '(') {
                st.push_back(i);
            }
            else if (s[i] == ')'){
                int j=i-1, i1 = st.back();
                
                for (int i1 = st.back()+1; i1 < j; i1++,j-- )
                    swap(s[i1],s[j]);
                st.pop_back();
            }
        }
        for (auto c : s)
            if (c != '(' && c != ')')
                ans +=c;
        return ans;
    }
};
