class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(begin(tokens),end(tokens));
        int N = tokens.size();
        if (N == 0 || tokens[0] > power) return 0;
        int i=0, j=N-1, ans = 0, s= 0, p = power;
        while (i<=j){
            if (tokens[i] <= p){
                p -= tokens[i++];
                s++;
            }
            else{
                p+=tokens[j--];
                s--;
            }
            ans = max(ans, s);
        }
        return ans;
    }
};