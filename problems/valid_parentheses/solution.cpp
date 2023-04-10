class Solution {
public:
    bool isValid(string s) {
        vector<int> stack;
        
        for (auto c : s){
            if ( c == ')'){
                if (stack.empty() || stack.back() != '(') return false;
                stack.pop_back();
            }
            else if ( c == '}'){
                if (stack.empty() || stack.back() != '{') return false;stack.pop_back();
            }
            else if ( c == ']'){
                if (stack.empty() || stack.back() != '[') return false;stack.pop_back();
            }
            else
                stack.push_back(c);

        }
        return stack.empty();
    }
};