class Solution {
public:
    
    class Trie{
        public:
            bool w;
            Trie * next[26]; 
        Trie(){
            w = false;
            for (int i =0; i<26; i++)
                next[i] = 0;
        }
    };
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
#if 1        
        if(s.length()==0 || wordDict.size()==0)return {};
        int arr[26]={};
        for(int i=0;i<wordDict.size();i++)
        {
            for(int j=0;j<wordDict[i].length();j++)
                arr[wordDict[i][j]-'a']++;
        }
        for(int i=0;i<s.length();i++)
        {
            if(arr[s[i]-'a']==0)return vector<string>();
        }
#endif        
        Trie * trie = new Trie(),*t;
        // prepare the Trie
        for (auto & w : wordDict){
            t =trie;
            for  (auto & c : w){
                int ch = c-'a';
                if (!t->next[ch])
                    t->next[ch]=new Trie();
                t=t->next[ch];
            }
            t->w=true;
        }
        int n= s.length();
        vector<int> wordEnd(n+1,0);
        wordEnd[0]=1;
        
        /*Contains parent of each index */
        vector<vector<int>> res(n+1,vector<int>(0));

        for (int i=0; i<n; i++){
            if (wordEnd[i]==0) continue;                      
            t = trie;
            int j=i;
            while (j<n && t->next[s[j]-'a']){
                t = t->next[s[j++]-'a'];
                if (t->w) {
                    wordEnd[j]=true;
                    res[j].push_back(i); // parent of j is i
                }
            }

        }
        if (wordEnd[n]){
            vector<string> r; 
            wb2(s,res,n, r,"");
            return r;
        }
        return vector<string>();
        
    }
    void wb2 (string &s, vector<vector<int>> & res, int i,vector<string> & r, string rs){
        if (i==0) {
            r.push_back(rs);
            return ;
        }
        const int n =s.length();
        for (auto j : res[i]){
            if (i == n)
                wb2(s,res,j,r,s.substr(j,i-j));
            else
                wb2(s,res,j,r,s.substr(j,i-j) + " " + rs); 
        }        
    }
};