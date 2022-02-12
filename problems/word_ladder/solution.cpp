class Solution {
public:
    int ladderLength(string be, string en, vector<string>& wl) {        
        unordered_set<string> set(begin(wl),end(wl));
        if (set.count(en)==0) return 0;
        int N = wl[0].size();
        queue<string> q ;q.push(be);
        int len=1;
        while(!q.empty()){
            int sz =  q.size();
            while (sz-- > 0 ){
                string &s = q.front();
                if (s == en) return len;
                for (int i=0; i<N; i++){
                    int ch = s[i];
                    for (char c= 'a'; c<='z'; c++){
                        if (c == ch) continue;
                        s[i]=c;
                        auto it = set.find(s);
                        if (it != set.end()){
                            set.erase(it);
                            q.push(s);
                        }
                    }
                    s[i]=ch;
                }                
                q.pop();
            }
            len++;
        }
        return 0;
    }
};