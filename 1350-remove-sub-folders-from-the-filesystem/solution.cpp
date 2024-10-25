class Solution {
public:
    struct Trie{
        //Trie * ch[26]= {};
        unordered_map<string, Trie *> c;
        bool end =false;
    };
        struct Trie t;
    bool add(string s){
        Trie * p = &t;
        for (auto i=0; i< s.size(); i++){
            if (s[i] == '/') continue;
            string s1;
            for (auto j=i; j<s.size() && (s[j] != '/'); j++ ){
                s1.push_back(s[j]);
            }
            
            if (!p->c.count(s1)) 
                p->c[s1] = new Trie;
            p = p->c[s1];
            if (p->end) return false;            
        }
        return p->end = true;
        
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>  ans;
        sort(begin(folder),end(folder),[&](auto &a, auto &b){return a.size() < b.size();});
        for (auto s : folder){
            if (add(s)) ans.push_back(s);
        }
        return ans;
    }
};
