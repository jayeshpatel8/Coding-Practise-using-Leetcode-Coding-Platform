class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1=0,b1=0,a2=0,b2=0;
        parse(num1, a1,b1);
        parse(num2, a2,b2);

        return to_string(a1*a2-b1*b2) + '+' + to_string(a1*b2 + a2*b1) + 'i';
    }
    void parse(string s, int& a, int&b){
        int num=0, sign=0;
        int i=0;
        for(;s[i] == '+' || s[i] == '-';i++) sign  = s[i] == '-';
        
        for(;s[i] >='0' && s[i] <='9';i++){
            num = num*10 + s[i]-'0';
        }
        a = num * (sign ? -1 : 1); num=0;
        for(;s[i] == '+' || s[i] == '-';i++) sign  = s[i] == '-';
            
        for(;s[i] >='0' && s[i] <='9';i++){
            num = num*10 + s[i]-'0';
        }
        b = num * (sign ? -1 : 1);
    }
};