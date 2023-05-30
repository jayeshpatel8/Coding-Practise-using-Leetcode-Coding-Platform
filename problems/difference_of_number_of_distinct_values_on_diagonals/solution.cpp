class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int  M =  grid.size(), N= grid[0].size();
        vector<vector<int>> top(M, vector<int>(N)),bot(top),ans(top);
        for (int i=0; i<M; i++){
            int f[51]={},f2[51]={};
            int cnt = 0, cnt2 = 0;
            for (int j=0,i1=i; j<N && i1<M; j++,i1++){
                top[i1][j] = cnt;
                cnt += (++f[grid[i1][j]]==1);            
                bot[M-1-i1][N-1-j] = cnt2;
                cnt2 += (++f2[grid[M-1-i1][N-1-j]]==1);
            }            
        }
        for (int j1=1; j1<N; j1++){
            int f[51]={},f2[51]={};
            int cnt = 0, cnt2 = 0;
            
            for (int j=j1,i1=0; j<N && i1<M; j++,i1++){
                top[i1][j] = cnt;
                cnt += (++f[grid[i1][j]]==1);            
                bot[M-1-i1][N-1-j] = cnt2;
                cnt2 += (++f2[grid[M-1-i1][N-1-j]]==1);            
            }                
        }
        for (int i=0; i<M; i++)
            for (int j = 0; j<N; j++)
                ans[i][j] = abs(top[i][j]  -bot[i][j]);            
        return ans;
    }
};