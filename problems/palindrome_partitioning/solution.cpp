class Solution {
public:
    int pal[16][16];
    int n;
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        
        n = s.size();
        //memset(pal,-1,sizeof(pal));
        vector<string> a;
        dfs(s,0,a);
        return ans;
    }
    void dfs(string &s, int i, vector<string>& a){
        
        if (i >= n){
            ans.push_back(a);
            return ;
        }

        for (int j=i; j < n; j++){
            if (s[i]==s[j] && (j-i<=2 || pal[i+1][j-1])){     
                pal[i][j]=true;
                a.push_back(s.substr(i,j-i+1));
                dfs(s,j+1,a);
                a.pop_back();
            }
        }
    }
    bool isPal(string & s, int i, int j){
        //if (pal[i][j] != -1) return pal[i][j];
        while(i<j){
            if (s[i]!=s[j]) return false;//pal[i][j] = false;
            i++,j--;
        }
        return true;//pal[i][j] = true;
    }
};