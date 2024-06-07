class Solution {
public:
    struct Trie{
        struct Trie * ch[26]={};
        bool word=false;
    }trie;
    void insert (string w){
        Trie * cur = &trie;
        for (auto c : w){
            if (!cur->ch[c-'a'])
                cur->ch[c-'a'] = new Trie();
            if (cur->word) return;
            cur = cur->ch[c-'a'];
        }
        cur->word=true;
    }

    int search(string w){
        Trie * cur = &trie;
        int length = 0;
        for (auto c : w){
            if (!cur->ch[c-'a']) return 0;
            cur = cur->ch[c-'a'];
            if (cur->word) return ++length;
            length++;
        }
        return length;
    }
    string replaceWords(vector<string>& dict, string sentence) {
        for (auto &w : dict)
            insert(w);
        string ans , w;
        stringstream ss(sentence);
        while(ss >> w)
        {
            int l = search(w);

            if (!ans.empty())  ans+=" ";
            if (!l) ans +=w;
            else ans += w.substr(0,l);
        }
        return ans;
    }
};
