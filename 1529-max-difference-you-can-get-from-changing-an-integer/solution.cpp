class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num),s1;
        s1=s;
        if (s1[0]!= '1' ) {
            for (auto& c : s1) if (c == s[0]) c='1';
        }
        else {
            char ch= '1';
            for (auto c : s) 
                if (c != '1' && c!='0'){
                    ch = c; break;
                }
            if (ch != '1')
                for (auto& c : s1)
                    if (ch == c) c = '0';
        }
        
        
        char ch= '9';
        for (auto c : s) 
            if (c != '9'){
                ch = c; break;
            }
        for (auto &c : s) if (c == ch) c='9';
        return stoi(s) - stoi(s1);
    }
};
