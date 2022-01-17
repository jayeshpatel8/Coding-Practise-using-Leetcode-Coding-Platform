class Solution {
public:
    int numWays(vector<string>& words, string t) {
        long freq[26][10002]={};
        int tn =t.size(), mod = 1e9 +7;        
        int ml=words[0].size();
        if (tn >ml) return 0;
        for (auto &w : words){
            for (int i=0;i<ml; i++) freq[w[i]-'a'][i+1]++;
        }
        
        for ( int i=0; i<26; i++){
            for (int j=1; j<=ml; j++){
                freq[i][j] +=freq[i][j-1];
            }            
        }
        
        vector<long> dp(ml+1);
        for (int i=ml-1,c = t[tn-1]-'a'; i>=0; i--){
            dp[i] = freq[c][ml] - freq[c][i] ;
        }
        
        for (int i=tn-2; i>=0; i--){
            vector<long> dp2(ml+1);
            for (int j=ml-2, c = t[i+1]-'a'; j>=0; j--){
                int c2 = t[i]-'a';
                dp2[j] = (dp[j+1] * (freq[c2][j+1] - freq[c2][j])  + dp2[j+1] )%mod;
            }
            swap(dp,dp2);
        }

        return dp[0];
    }
};