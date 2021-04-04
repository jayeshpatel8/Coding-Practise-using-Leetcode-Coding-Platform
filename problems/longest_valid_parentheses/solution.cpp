class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans=0;
        
        for (int i=0; i<s.size(); i++){
            if (s[i] == '(') st.push(i);
            else {
                if (!st.empty() && s[st.top()]=='(') 
                    st.pop();
                else
                    st.push(i);
            }
        }
        
        int start, end=s.length();
        while (!st.empty()){
            start=st.top(); st.pop();
            ans  = max(ans, end-start-1);
            end=start;
        }
        return max(ans, end);
    }
};