class Solution {
public:
    unordered_set<string> W,s,e;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (auto w  : wordList) W.insert(w);        
        if (W.find(endWord) == W.end()) return 0;
        s.insert(beginWord); 
        e.insert(endWord);
        W.erase(beginWord);W.erase(endWord);
        int l=1,N=beginWord.length();
        while (!s.empty() && !e.empty()){
            if (s.size()>e.size()) s.swap(e);
            
            unordered_set<string> t;
            for (auto &st : s){                  
                cout << st << " ..";
                string  cur = st;
                for (int i=0; i<N; i++){
                    char ct= cur[i];                     
                    for (char c = 'a'; c<='z'; c++){                        
                        cur[i]=c;          
                        if (e.count(cur)) return 1+l;
                        if (W.find(cur) != W.end()){
                            W.erase(cur);
                            t.insert(cur);
                        }                        
                    }
                    cur[i]=ct;
                }
            }
            s.swap(t);
            l++;
        }
        
        return 0;
    }

};