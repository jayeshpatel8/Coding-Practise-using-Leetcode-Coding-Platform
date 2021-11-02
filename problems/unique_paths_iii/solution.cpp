int uniquePathsIII_(vector<vector<int>>& grid, int cnt, int i, int j){
     int r =grid.size(), c=grid[0].size();
        
    if (grid[i][j]==2 ) 
        return cnt==0;
    
    if (grid[i][j]==3 || grid[i][j]==-1) return 0;
    grid[i][j]=3;
    cnt--;
    int ret=0;
    if (i>0 ){        
        ret += uniquePathsIII_(grid,cnt,i-1,j);
    }
    if (j>0){
        ret += uniquePathsIII_(grid,cnt,i,j-1);
    }    
    if (i+1<r ){        
       ret +=  uniquePathsIII_(grid,cnt,i+1,j);
    }
    if (j+1<c ){
        ret += uniquePathsIII_(grid,cnt,i,j+1);
    }    
    cnt++;
    grid[i][j]=0;
    return ret; 
    
}
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int r =grid.size(), c=grid[0].size();
        vector<vector<bool>> used(r,vector<bool>(c,0));
        int cur=0,cnt=r*c-1;
        int i ,j,si=-1,sj=0;
        
        for (i=0; i<r; i++)
            for (j=0; j<c; j++){
                if (grid[i][j]==1){
                    si=i,sj=j;
                }
                else if (grid[i][j]==-1) cnt--;
            }
        if (cnt<1 || si==-1) return cur;
        cur = uniquePathsIII_(grid,cnt,si,sj);
        return cur;        
    }
};