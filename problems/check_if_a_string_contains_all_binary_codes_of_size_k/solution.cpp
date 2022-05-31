class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int mask = (1<<k)-1;
        vector<bool> vis(mask+1);
        int n=0;
        for (int i=0; i<s.size(); i++){
            n= n<<1 & mask | s[i]-'0' ;
            if (i>=k-1) 
                vis[n]=true;
        }
        return find(begin(vis),end(vis),0) == end(vis);
    }
};