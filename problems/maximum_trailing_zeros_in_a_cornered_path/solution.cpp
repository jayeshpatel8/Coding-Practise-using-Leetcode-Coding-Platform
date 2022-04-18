class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m =grid.size(), n= grid[0].size();
        vector<vector<int>> r2(m+1,vector<int>(n+1)),r5(r2),c2(r2),c5(r2);
        for (int i=0;i<m; i++){
            for (int j=0;j<n; j++){
                int cnt2 =0 ,cnt5=0;                   
                int n = grid[i][j];
                while((n & 1) == 0) n/=2, cnt2++;
                n = grid[i][j];
                while (n % 5 == 0) n/=5, cnt5++;
                int cr=i+1,cc=j+1,pr=i,pc=j;
                r2[cr][cc] = r2[cr][pc] + cnt2;
                r5[cr][cc] = r5[cr][pc] + cnt5;
                c2[cr][cc] = c2[pr][cc] + cnt2;                
                c5[cr][cc] = c5[pr][cc] + cnt5;                       
             }
        }

        int ans= 0;
        for (int i=0;i<m; i++){
            for (int j=0;j<n; j++){
                int cr=i+1,cc=j+1,pr=i,pc=j;
                // l,u,r,d
                int cnt2[5] = {r2[cr][cc],c2[pr][cc],r2[cr][n] - r2[cr][pc],c2[m][cc] - c2[cr][cc],r2[cr][cc]};
                int cnt5[5] = {r5[cr][cc],c5[pr][cc],r5[cr][n] - r5[cr][pc],c5[m][cc] - c5[cr][cc],r5[cr][cc]};
                for (int r=0; r<4; r++){
                    ans= max (ans , min( cnt2[r] +cnt2[r+1] , cnt5[r] +cnt5[r+1] ));
                }
            }
        }
        return ans;
    }
};