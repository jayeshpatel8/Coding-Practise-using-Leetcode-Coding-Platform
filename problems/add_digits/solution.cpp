class Solution {
public:
    int addDigits(int num) {
        string s =  to_string(num);
        while(s.size() >1 ){
            int n = 0;
            for (auto c : s) n += c-'0';
            s= to_string(n);
        }
        return s[0]-'0';
    }
};