class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int y[4] = {1,0,-1,0};
        int x[4] = {0,1,0,-1};
        
        int rc[2]={n,n-1};
        int dir=0,idir=0;
        int r=0,c=-1;
        int num=1;
        vector<vector<int>> res(n,vector<int>(n,0));
        while(rc[dir%2]){
            for (int i=0;i<rc[dir%2]; i++){                
                r+=x[idir ];c+=y[idir];
                res[r][c]=num++;                
            }
            idir = (idir+1)%4;
            rc[dir]--;
            dir = (++dir)%2;            
        }
        return res;
    }
};