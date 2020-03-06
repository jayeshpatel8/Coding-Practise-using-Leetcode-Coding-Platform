bool checkValidMove(vector<string> &s,int r,int c){
    int n = s.size();
    // check for col
    for (int i =0; i<n; i++)
        if (s[i][c]=='Q' ) return false;
    // right cross check
    for (int i =r-1,j=c-1;  i>=0 && j >=0; i--,j--)
        if (s[i][j]=='Q') return false;        
    for (int i =r-1,j=c+1;  j<n && i>=0 ; i--,j++)
        if (s[i][j]=='Q') return false;
    return true;
}
void Queens(vector<string> &s ,vector<vector<string>> & sl ,int r){
    int n = s.size();
    if (r == n) {
        sl.push_back(s);
        return ;
    }
    for (int c=0; c<n; c++){

        if (checkValidMove(s,r,c))
        {
            s[r][c]='Q';
            Queens(s,sl,r+1);
                s[r][c]='.';   
        }             
    }
}
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
         
        vector<string> s(n,string(n,'.'));
        vector<vector<string>> sl;
        Queens(s,sl,0);
        return sl;
    }
};