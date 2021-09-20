class Solution {
public:
    string best="";
    vector<char> ch;
    string longestSubsequenceRepeatedK(string s, int k) {
        int freq[128]={};
        for (auto c : s) freq[c]++;
        for (int i='a'; i<='z'; i++)
            if (freq[i]>=k) ch.push_back(i);
        dfs("",s,k);
        return best;
    }
    void dfs(string c, string &s, int k){
        if (!check(c,s,k)) return;
        if  (c.size() >= best.size()) best = c;
        for (auto i : ch)
            dfs(c+i,s,k);
    }
    bool check(string& cur, string &s, int k){
        int i=0,r=0;
        if(cur=="") return true;
        for (auto c : s){
            if (c == cur[i]){
                i++;
                if (i == cur.size()){
                    i=0;
                    if (++r == k) return true;
                }
            }
        }
        return false;
    }
};