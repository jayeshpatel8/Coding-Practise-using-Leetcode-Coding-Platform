class Solution {
public:
int dp[1001][26][26]= {};
    int minimizeConcatenatedLength(vector<string>& words) {
        return words[0].size() + dfs(words,1,words[0][0]-'a',words[0].back()-'a');
    }
    int dfs(vector<string> & words, int i,int start, int end){
        if (i == words.size()) return 0;
        if (dp[i][start][end]) return dp[i][start][end];
        auto &w = words[i];
        int ans = w.size() + min( - (w[0]-'a'==end) + dfs(words,i+1,start,w.back()-'a'),
         - (w.back()-'a'==start) + dfs(words,i+1,w[0]-'a',end)
        );

        return dp[i][start][end] =ans;
    }
};