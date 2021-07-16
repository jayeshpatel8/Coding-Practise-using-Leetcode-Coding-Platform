
class Solution {
public:
    vector<vector<int>>sticker;
    int minStickers(vector<string>& stickers, string target) {
        int n=target.size();
        int m=stickers.size();
        sticker.resize(m,vector<int>(26,0));
        for(int i=0;i<stickers.size();i++)
            for(auto &x:stickers[i])sticker[i][x-'a']++;

        int N=(1<<n);
        vector<int>dp(N,30);
        dp[0]=0;
        for (int t=0; t<N; t++){
            if (dp[t]>=30) continue;
            for (auto &s : sticker){
                vector<int>stic=s;
                int temp = t;
                for (int i=0; i<n; i++){
                    if (((t>>i)&1) == 0 && stic[target[i]-'a']){
                        stic[target[i]-'a']--;
                        temp |= (1<<i);
                    }
                }
                dp[temp] = min(dp[temp], 1 + dp[t]);

            }
            
        }
        if(dp[N-1]==30)return -1;
        return dp[N-1];
    }


};
