struct trie{
    trie * ch[26]={};
    bool word=false;
    void add(string& s){
        trie * root = this;
        int c ;
        for( auto &i : s){
            c = i-'a';            
            if(root->ch[c]==0)
                root->ch[c] = new trie();
            root = root->ch[c];
        }
        root->word=true;
    }
    bool search(string & s){
        int N = s.size();
        vector<int> dp(N+2);
        dp[0]=true;
        
        for(int i =1; i<=N; i++){
            if(!dp[i-1]) continue;
            trie *root = this;
            int j = i-1;
            for ( ; j<N; j++){
                int c = s[j]-'a';
                dp[j] |=root->word;
                if(!root->ch[c]) { break;}
                root = root->ch[c];
                
            }
            if (j==N && root->word) return true;
        }
        
        return false;
    }
};

class Solution {
public:

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(begin(words),end(words),[&](string &s1, string &s2){return s1.size() < s2.size();               });
        trie root;
        vector<string> ans;
        for ( auto &i : words){
            if (root.search(i)) ans.push_back(i);
            root.add(i);
        }        
        return ans;
    }
};