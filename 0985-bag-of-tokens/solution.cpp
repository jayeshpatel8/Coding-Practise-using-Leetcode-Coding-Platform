class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(begin(tokens),end(tokens));
        if (tokens.size() <1 || tokens[0] > power) return 0;
        int p = power , ans= 0 , t=0;
        for (int i=0,j=tokens.size()-1; i<=j;  ){
            if (tokens[i] <=p){
                p -= tokens[i++];
                t++;
            }
            else if (t > 0){
                p += tokens[j--];
                t--;

            }
            else break;
            ans = max(ans, t);
        }
        return ans;
    }
};
