class Solution {
public:
    struct Trie{
        Trie *ch[26]={};
        bool w=false;
    } trie;
    bool insert(string &s){
        Trie *t = &trie;
        bool news = false;
        for (int i=s.size()-1; i>=0; i--){
            int c = s[i];
            if (!t->ch[c-'a'])
                t->ch[c-'a'] = new  Trie, news = true;
            t = t->ch[c-'a'];            
        }
        
        if (!news) return false;

        return t->w=true;
        
    }
    

    int minimumLengthEncoding(vector<string>& words) {
        
        sort(words.begin(), words.end(), [](auto &s1, auto &s2){return s1.length()>s2.length();});
        int ans = 0;
        for (auto &w : words){
           if(insert(w))
               ans += w.size() +1 ;
        }
        return ans;
    }
    int minimumLengthEncoding2(vector<string>& words) {
        sort(begin(words),end(words),[](auto &a, auto &b){return a.size() > b.size();});
        
        string ans;
        for (auto &w : words){
             w+='#';
            if (ans.find(w) != string::npos) continue;
            ans += w;
        }
      
        return ans.size();
    }
};