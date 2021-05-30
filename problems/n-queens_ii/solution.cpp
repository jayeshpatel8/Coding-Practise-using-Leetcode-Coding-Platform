class Solution {
public:
    int N;
    int totalNQueens(int n) {
        vector<vector<bool>> board(n,vector<bool>(n,0));
        int cnt=0;
        N=n;
        nq(board, 0,cnt);
        
        return cnt;
    }
    void nq(vector<vector<bool>>& B, int r, int & cnt){
        if ( r == N ) { cnt++; return; }
        
        for (int c=0; c<N; c++){
            if (isAllowed(B,r,c)){
                B[r][c]=1;
                nq(B, r+1,cnt);
                B[r][c]=0;
            }
        }
    }
    bool isAllowed(vector<vector<bool>>& B, int r, int c){
        
        for (int i=0; i<r; i++){
            if (B[i][c]) return false;
        }        
        for (int i=r-1,j=c-1; i>=0 && j >=0; i--,j--){
            if (B[i][j]) return false;
        }
        for (int i=r-1,j=c+1; i>=0 && j<N; i--,j++){
            if (B[i][j]) return false;
        }        
        return true;
    }
   
};