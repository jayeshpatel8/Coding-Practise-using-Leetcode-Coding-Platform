class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st,st2;
        int ans=0,len=0;
        for (int i=0; i<s.size(); i++){
            if(s[i] =='(')len++;
            else if(s[i-1] =='(') ans += 1 << --len;
            else len--;
        }
        return ans ;
    }
    int score(string &s, int i, int j){
        if (i>=j)return 0;
        if (i+1 == j) return 1;
        if (s[i+1]==')') return 1 + score(s,i+2,j);
        return 2 * score(s,i+1,j-1);
    }
};