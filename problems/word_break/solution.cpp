class Solution {
public:
struct trie{
    trie * ch[26]={0};
    bool w=false;
}root;
int dp[301];
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        for (auto &s : wordDict){
            trie *r = &root;
            for (auto c : s){
                if (!r->ch[c-'a'])
                    r->ch[c-'a'] =  new trie();
                r = r->ch[c-'a'];
            }
            r->w=true;
        }   
      return dfs(s);  
    }
    bool dfs(string &s , int i=0){
        if (i>= s.size()) 
            return true;
            if (dp[i] != -1) return dp[i];
        trie *r = &root;
        for (int j=i; j<s.size(); j++){           
            if (r->ch[s[j]-'a'] ){
                r=r->ch[s[j]-'a'];
                if (r->w && dfs(s,j+1))
                    return dp[i] = true;
            }
            else return dp[i] = false;
        }
        return dp[i] = false;
    }
};