class Solution {
public:
    int dp[301][27][27]={};
    int minimumDistance(string word) { 
        return dfs(word,0,26,26);
    }
    int dfs(string & W, int i, int ch1, int ch2){
        if (i >= W.size()) return 0;
        
        if (dp[i][ch1][ch2]) return dp[i][ch1][ch2];
        int ans, ch = W[i]-'A';
        if (ch == ch1)
            ans = dfs(W,i+1,ch,ch2 );
        else if (ch == ch2)
            ans = dfs(W,i+1,ch1,ch );
        else
            ans = min( cost(ch1,ch) + dfs(W,i+1,ch,ch2 ), cost(ch2,ch) + dfs(W,i+1,ch1,ch ));
        return dp[i][ch1][ch2] = ans;
    }
    int cost(char ch1, char ch){
        if(ch1 >= 26) return 0;
        
        int r1 = ch1/6,c1=ch1%6, r=ch/6,c=ch%6;
        return abs(r1-r)+abs(c1-c);
    }
};