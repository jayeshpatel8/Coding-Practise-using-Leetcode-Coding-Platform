class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        queue<pair<int,int>> q;
        vector<int> maxi(N),maxj(M);
        q.push({0,0});
        int step=0;
        while (!q.empty()){
            int sz = q.size();
            step++;
            while (sz-- > 0){
                auto  [i,j] = q.front(); q.pop();
                if (i==M-1 &&  j==N-1) return step;
                for (int k=max(j,maxj[i])+1; k<N && (k-j <= grid[i][j]); k++)
                    q.push({i,k});
                for (int k=max(i,maxi[j])+1; k<M && (k-i <= grid[i][j]); k++)
                    q.push({k,j});
            ;                    
                    maxi[j]=max(maxi[j], grid[i][j]+i);
                    maxj[i]=max(maxj[i], grid[i][j]+j);
            }
        }
        return -1;
    }
};