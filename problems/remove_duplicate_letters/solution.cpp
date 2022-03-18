class Solution {
public:
    string removeDuplicateLetters(string s) {
        int f[256]={};
        bool vis[256]={};        
        for (auto & c : s) f[c]++;
        
        string ans="0";
        for (auto c : s){            
            f[c]--; 
            if (vis[c]) continue;
            while(ans.back() > c && f[ans.back()]){
                vis[ans.back()]=false;
                ans.pop_back();
            }
            ans.push_back(c);
            vis[c]=true;
        }
        return ans.substr(1);
    }
};