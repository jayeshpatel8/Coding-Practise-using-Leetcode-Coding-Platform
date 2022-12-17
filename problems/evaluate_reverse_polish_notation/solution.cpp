class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        //using fp = int f (int a , int b);
        typedef int (*fp)(int , int);
        map<string,fp> s = {{"+",[](auto a, auto b)->int{return (long)a + b;}},{"-",[](auto a, auto b)->int{return (long)a - b;}},{"/",[](auto a, auto b)->int{return (long)a / b;}},{"*",[](auto a, auto b)->int{return (long)a * b;}}};// "-", "/", "*"};
        for (auto i :tokens){
            if ( s.count(i)){
                int b = (st.top());
                st.pop();
                long a  =  (st.top());
                st.pop();
                st.push((s[i](a,b)));
            }
            else
                st.push(stoi(i));
        }
        return st.top();
    }
};