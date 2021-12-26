class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        unordered_map<char,pair<int,int>> m;
        vector<int> ans;
        for (int i=0; i<s.size(); i++){

            ans.push_back(dfs(n,startPos[0],startPos[1],s,i));
        }
        return ans;
    }
    int dfs(int n, int r, int c, string& s, int i){
        if (i ==  s.size() ) return 0;
        if (s[i] == 'U' || s[i] == 'D') 
            r =  r + (s[i] == 'U'? -1 : 1);
        else
            c += (s[i] == 'L' ? -1 : 1);
        if ( r < 0 || c < 0 || r==n || c==n) return 0;
        return 1 + dfs(n,r,c,s,i+1);
    }    
};