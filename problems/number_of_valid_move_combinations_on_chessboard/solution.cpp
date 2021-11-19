class Solution {
public:
    int vis[4][8][8] = {};
    int dir[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int countCombinations(vector<string>& pieces, vector<vector<int>>& pos, int p = 0)     {
        if (p >= pieces.size()) return 1;
        int i = pos[p][0] -1, j = pos[p][1]-1, cnt = 0;
        
        for (int d = 0; d<8; d++){
            if ((d < 4 && pieces[p] == "bishop" ) || (d >= 4 && pieces[p] == "rook"))
                continue;
            bool blocked = false;
            for ( int step = cnt == 0 ? 1 : 2; !blocked; step++){
                int x = i + (step - 1) * dir[d][0], y = j + (step - 1) * dir[d][1];    
                
                if (min(x,y) < 0 || max(x,y) > 7) break;
                
                bool canVisit = true;
                for(int pp = 0; pp<p; pp++){
                    canVisit &= vis[pp][x][y] >=0 && vis[pp][x][y] < step;
                    blocked |= (vis[pp][x][y] < 0 && -vis[pp][x][y] <=step) || (vis[pp][x][y]==step);
                }
                if (canVisit){
                    vis[p][x][y] = -step;
                    cnt +=countCombinations(pieces,pos,p+1);
                }
                vis[p][x][y] = step;
            }
            fill_n(vis[p][0], 64, 0);
        }
        return cnt;
    }
};