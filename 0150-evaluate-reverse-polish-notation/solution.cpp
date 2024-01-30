class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        for (auto&i : tokens){
            if (i=="+" || i=="-" || i=="/" || i=="*"){
                int a = st.back();
                st.pop_back();
                int b = st.back();
                st.pop_back();
                if (i == "+") st.push_back(a+b);
                else if (i == "-") st.push_back(b-a);
                else if (i == "*") st.push_back(a*b);
                else st.push_back(b/a);
            }
            else st.push_back(stoi(i));
        }   
        return st.back();
    }
};
