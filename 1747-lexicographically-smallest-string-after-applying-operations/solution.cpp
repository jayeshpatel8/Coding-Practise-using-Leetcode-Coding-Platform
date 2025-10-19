class Solution {
public:
    string ans;
    int n=0;
    unordered_set<string> vis;
    string findLexSmallestString(string s, int a, int b) {
        string t; 
        for (auto c : s)  t.push_back(c- '0');
        n = s.size(); ans = t;
        dfs(t,a,b);
        for (auto &c : ans)  c = c + '0';
        return ans;
    }
    void dfs (string &  s ,  int a, int b){
        if (vis.count(s)) return;
                vis.insert(s);
        if (ans > s ) ans = s;
        {
            string t = s.substr(n-b) + s.substr(0,n-b);
            dfs(t,a,b);
        }
        
        for ( int i=1; i<n; i+=2){                
            s[i] = (s[i] + a) % 10;
        }        
        dfs(s,a,b);
    }
};
