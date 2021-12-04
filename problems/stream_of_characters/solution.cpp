class StreamChecker {
public:
    struct Trie{
        Trie * c[26]={};
        bool w=false;
    };
    Trie root;
    string str;
    StreamChecker(vector<string>& words) {
        
        for (auto s : words){
            Trie *t = &root;
            for (int i=s.size()-1; i>=0; i--){
                int c = s[i]-'a';
                if (!t->c[c]){
                    t->c[c] = new Trie;
                }                
                t=t->c[c];
            }
            t->w=true;
        }
    }
    
    bool query(char letter) {
        str +=letter;
        Trie *t = &root;
        for (int i=str.size()-1; i>=0; i--){
                int c = str[i]-'a';
                if (t->c[c]){
                    t= t->c[c];
                }   
                else return false;
            if (t->w) return true;
        }
        
        return false;
        
    }
};
/*
aaaaab
a
aa
aaa
aaaab

*/
/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */