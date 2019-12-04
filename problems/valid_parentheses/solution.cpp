#include <stack>
class Solution {
public:
    bool isValid(string s) {
        
        std::stack<char> st;
        int size= s.length();
        
        for (int i=0; i < size; i++)
        {
            if (s[i] == '{' || s[i] == '[' || s[i]=='(')
                st.push(s[i]);
            else{
                if (st.empty())
                    return false;
                char p = st.top();
                if (s[i] == ')' && p != '(')
                    return false;
                if (s[i] == '}' && p != '{')
                    return false;
                if (s[i] == ']' && p != '[')
                    return false;
                st.pop();
            }
        }
        return st.empty();
            
    }
};