class Solution {
public:
bool pal[16][16]={};
vector<vector<string>> ans;
int N ;
    vector<vector<string>> partition(string s) {
        vector<string> s1;
        N=s.size();
        dfs(s,s1, 0);
        return ans;
    }
    void dfs(string &s, vector<string> & pals, int i ){
        if (i == N){
            ans.push_back(pals);
            return;
        }
        for (int j=i; j<N; j++){
            if (s[i]==s[j] && (j-i<=2 || pal[i+1][j-1])){
                pal[i][j]=true;
                pals.push_back(s.substr(i,j-i+1));
                dfs(s,pals,j+1);
                pals.pop_back();
            }
        }
    }
};
