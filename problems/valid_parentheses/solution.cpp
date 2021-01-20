class Solution {
public:
    bool isValid(string s1) {
        stack<char> s;
        unordered_map<char,char> map={{'{','}'},{'[',']'},{'(',')'}};
        for (auto c : s1){
            if (c == '{' || c == '[' || c =='('){
                s.push(c);
            }
            else if (!s.empty() && c==map[s.top()]){
                s.pop();
            }
            else
                return false;
        }
        return s.empty();
    }
};