class Solution {
public:
    int dp[71][8][8][8][8];
    int fx,fy,M,N, mj,cj;
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        int mx,my,cx,cy;
        mj = mouseJump, cj = catJump;
         M = grid.size(), N = grid[0].size();
        for (int i=0;i<M; i++){
            for (int j=0; j<N; j++){
                if (grid[i][j]=='.' ||grid[i][j]=='#') continue;
                if (grid[i][j] == 'C')
                    cx=i,cy=j;
                else if (grid[i][j] == 'M')
                    mx=i,my=j;
                else
                    fx=i,fy=j;
            }
        }
        memset(dp,-1,sizeof(dp));
        
        return dfs(grid,0,mx,my,cx,cy); //dp[0][mx][my][cx][cy]==1;
    }
    int dirs[5] = {0,1,0,-1,0};
    bool dfs(vector<string>& grid, int turn, int mx,int my,int cx,int cy){   
        bool cat = turn&1;
        if ((mx==cx && my==cy) ) return cat;
        if (turn>70) return true;
        if (mx==fx && my==fy)  return !cat;
        if (cx==fx && cy==fy)  return cat;
       
        if (dp[turn][mx][my][cx][cy] != -1) return dp[turn][mx][my][cx][cy];
        int curx =mx,cury=my,tN = (turn&1) ? cj : mj ;
        if (cat)  curx =cx,cury=cy;
        bool win=false;
        for (int d=0; d<4; d++){
            for (int i = 0; i<=tN; i++ ){
                int x = curx + dirs[d]*i;
                int y = cury + dirs[d+1]*i;
                if (x>=0 && x<M && y>=0 && y<N && grid[x][y] != '#'){
                    if (cat){
                        if (!dfs(grid,turn+1,mx,my,x,y)){
                            win=true; break;
                        }                        
                    }
                    else{
                        if (!dfs(grid,turn+1,x,y,cx,cy)){
                            win=true; break;
                        }
                    }                    
                }
                else break;
            }
            if (win)break;
        }
        dp[turn][mx][my][cx][cy] = win ;
        return win;
    }
};

