class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int64_t> num;
        
        for (auto s : tokens){
            if (s.size() ==1 && (s[0] =='+' || s[0] =='-' || s[0] =='*' || s[0] == '/')){
                int64_t r, n1,n2;
                n2 = num.top(); num.pop();
                n1 = num.top(); num.pop();
                switch (s[0] ){
                    case '+':
                        r  = n1 + n2;
                        break;
                    case '-':
                        r  = n1 - n2;
                        break;
                    case '*':
                        r  = n1 * n2;
                        break;
                    case '/':
                        r  = n1 / n2;
                        break;
                }
                num.push((int64_t)r);
            }
            else{
                num.push(stoi(s));
            }
        }
        return num.top();
    }
};