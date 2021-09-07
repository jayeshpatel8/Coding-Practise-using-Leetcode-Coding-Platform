class Solution {
public:
    int wstart[18]={};
    int wsize[18]={}  , dp[1000]={};
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),end(words),[](auto & s1, auto&s2){return s1.size() < s2.size();});
        for ( auto i =0; i< words.size(); i++){
            int sz = words[i].size();
            if (wsize[sz] == 0) wstart[sz]= i;
            wsize[sz]++;
        }        
        
        int ans = 0;
        for (int i = 0;i<words.size();i++){
            int sz = words[i].size()+1;
            for (int j = wstart[sz], jend = j + wsize[sz]; j<jend; j++ ){
                if (isCommSeq(words[i],words[j])){
                    dp[j] =max(dp[j], 1 + dp[i]);                    
                }
            }
            ans = max(ans, dp[i]);
        }
        return ++ans;
    }
    /*
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),end(words),[](auto & s1, auto&s2){return s1.size() < s2.size();});
        memset(dp,-1,sizeof(dp));
        for ( auto i =0; i< words.size(); i++){
            int sz = words[i].size();
            if (wsize[sz] == 0) wstart[sz]= i;
            wsize[sz]++;
        }
        int ans = 0;
        for ( int i=0; i<words.size(); i++){
            ans = max(ans, dfs(words, i));
        }
        return ++ans;
    }
    int dfs(vector<string>& words, int i){
        if (i >= words.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0, sz =  words[i].size();;
        for ( int j=wstart[sz+1], end = j + wsize[sz+1]; j<end; j++){
            if (isCommSeq(words[i],words[j])){
                ans  = max( ans, 1  + dfs(words, j));
            }            
        }        
        
        return dp[i] = ans;
    }*/
    bool isCommSeq(string & s1, string & s2){
        int i=0, j=0;
        for (; j<s2.size(); j++){
            if (s1[i] ==s2[j]) i++;
        }
        return (i == s1.size());
    }
};