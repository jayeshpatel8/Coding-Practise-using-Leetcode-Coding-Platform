class Solution {
public:
    int mystoi(string s){
        int r=0;
        int i=0;
        int m=1;

        if (s[0]=='-' && (s.length() >1)) { m=-1;i=1; }
        for (; i<s.length(); i++)
                r = s[i] - '0' + (r * 10);
        return r * m;
    }
    int evalRPN(vector<string>& tokens) {
       stack<int> st;
        long int r=0;
       for (auto s : tokens){
           if (s.length() > 1 || s[0] >= '0' && s[0] <='9'){
               st.push(stoi(s));
           }
           else{
               int b = st.top(); st.pop();
               int a = st.top(); st.pop();
               
               if(s[0]=='+')         st.push(a + b); 
               else if(s[0] == '-')  st.push(a - b);
               else if(s[0] == '*')  st.push(a * b);
               else                  st.push(a / b);
           }
               
       }
        return st.top();
    }
};