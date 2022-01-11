class Solution {
public:
    int kSimilarity(string s1, string s2) {
        queue<string> q;
        unordered_set<string> vis;
        int level=0, n= s1.size();
        q.push(s1);
        vis.insert(s1);
        while(!q.empty()){
            int sz = q.size();
            while (sz-- > 0){
                auto st = q.front(); q.pop();
                if (st == s2) return level;
                int i=0;
                for (; i<n && st[i]==s2[i]; i++){
                    ;
                }
                for (int j=i+1; j<n ; j++){
                    if (st[j]==s2[i] && st[j] != s2[j]){
                        swap(st[i],st[j]);
                        if (vis.count(st) == 0){
                            vis.insert(st);
                            q.push(st);
                        }
                        swap(st[i],st[j]);
                    }
                }
            }
            level++;
        }
        return level;
    }
};