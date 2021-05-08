class Trie{
    public:
    Trie * ch[28];
    int in;
    Trie(){
        memset(ch,0,sizeof(ch));
        in = -1;
        
    }
    void insert(string & s, int in){
        Trie *ptr=this;
       
        for (auto ch : s){
            int c =   ch - 'a';
            if (!ptr->ch[c])   ptr->ch[c] = new Trie();                      
            
            ptr = ptr->ch[c];
        }
         ptr->in = in;
        
    }
    int search(string & s){
     
      Trie *ptr=this;
      for (auto ch:s){
          int c =   ch - 'a';
          if (!ptr->ch[c])      return -1;
          ptr =ptr->ch[c];
      } 
        
        return ptr->in;
        
    }
};

class WordFilter {
public:
    Trie tr; 
    WordFilter(vector<string>& words) {
        int n = words.size();
        for(int pos = 0; pos < n; pos++) {
            string s = words[pos];
            for(int i = 0; i < (int) s.size(); i++) {
                for(int j = (int) s.size() - 1; j >= 0; j--) {
                    string a = s.substr(0, i + 1) + '|' + s.substr(j);
                    tr.insert(a, pos);
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string s = prefix + "|" + suffix;
        return tr.search(s);   
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */