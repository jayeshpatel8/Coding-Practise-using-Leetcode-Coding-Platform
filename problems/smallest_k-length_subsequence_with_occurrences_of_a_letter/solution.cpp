class Solution {
public:
    string smallestSubsequence(string s, int k, char l, int rep) {
        int N = s.size(), cnt_l = count(begin(s),end(s),l);
        string stack;
        for( int i=0; i<N; i++){
            char c = s[i];
            while(!stack.empty() && stack.back() > c && (N - i + stack.size() > k) && (stack.back() != l || cnt_l > rep)){
                if (stack.back() == l) rep++;
                stack.pop_back();
            }

            if (stack.size() < k){
                if (c == l) {
                    rep--; stack+=c;;
                }
                else if ((k-(int)stack.size()) > rep){
                    stack+=c;
                }
            }
            if (c == l) cnt_l--;
        }
        return stack;
    }
};