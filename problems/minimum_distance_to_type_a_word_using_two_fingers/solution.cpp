class Solution {
public:
    int dp[30][30][301];
    array<int,2> dist[128];
    int minimumDistance(string word) {
        memset(dp,-1,sizeof(dp));
        int ans = INT_MAX;
        for(  int i=0, l='A'; i<5; i++){
            for (int j = 0; j<6; j++,l++){
                dist[l][0]=i, dist[l][1]=j;
            }
        }
        for ( int i='A'; i<'Z'; i++){
            for (int j=i+1; j<='Z'; j++){
                ans = min (ans, dfs(word,0,i,j));
            }
        }
        return ans;
    }
    int dfs(string& word,int i, int k1, int k2){
        if (i >= word.size()) return 0;
        if (dp[k1-'A'][k2-'A'][i] != -1) return dp[k1-'A'][k2-'A'][i];
        int ans ;
        // move k1        
        ans =  abs(dist[k1][0] - dist[word[i]][0]) + abs(dist[k1][1] - dist[word[i]][1]) + dfs(word,i+1,word[i],k2);
        ans =min (ans,abs(dist[k2][0] - dist[word[i]][0]) + abs(dist[k2][1] - dist[word[i]][1]) + dfs(word,i+1,k1,word[i]) );
        
        return dp[k1-'A'][k2-'A'][i] = ans;
    }
};