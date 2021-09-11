class Solution {
public:
    int i=0;
    int calculate(string &s) {        
        int sign = 0, ans = 0;
        for( ;i< s.size(); ){
            if (s[i] >= '0' && s[i] <='9'){
                int n = 0;
                while (i<s.size() && s[i] >= '0' && s[i] <='9' ){
                    n = n * 10 + (s[i++]-'0');
                }
                if (sign) ans -= n;
                else ans +=n;
                continue;
            }
            else if (s[i]=='+') sign = 0;
            else if (s[i]=='-') sign = 1;
            else if (s[i]=='(') {
                ++i;
                if (sign) ans -= calculate(s);
                else ans +=calculate(s);
            }
            else if (s[i]==')') return ans;
            i++;
        }
        return ans;
    }   
};
/*class Solution {
public:
    
    int calculate(string s) {
        int  n = 0, ans = 0, sign  = 1;
        stack<int> st;
        for (auto i : s){
            
            if (i ==' ') continue;
            else if (isdigit(i)){
                n = n * 10 + (i - '0');
            }
            else if (i == '+')
                ans += sign * n, sign = 1, n = 0;
            else if (i == '-')
                ans += sign * n, sign = -1, n = 0;
            else if (i == '('){
                st.push(ans);st.push(sign);
                ans = n = 0, sign = 1;
            }
            else if (i == ')'){                
                ans += sign * n;
                ans *= st.top(); st.pop();
                ans += st.top() ;st.pop();
                n = 0, sign = 1;
            }            
        }
        if(n) ans += sign * n;
        return ans;
    }
};*/