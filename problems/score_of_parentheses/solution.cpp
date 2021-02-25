class Solution {
public:
    int scoreOfParentheses(string S) {
        int res=0;
        int len=0;
        for (int i=0; i< S.size(); i++){
            if (S[i]=='(') len++;
            else if (S[i-1]=='(')  res += 1 << --len;
            else --len;
        }
        return res;
    }
};