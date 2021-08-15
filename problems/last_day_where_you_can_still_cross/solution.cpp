class Solution {
public:
    int uf[20001];
    int find(int n){
        if (uf[n] < 0 ) return n;
        return uf[n] = find(uf[n]);
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int dir[5] =  {0,1,0,-1,0};
        for ( int i=0; i<20001; i++) uf[i] = INT_MIN;
        //memset(uf,-1,sizeof(uf));
        for (int d = cells.size()-1; d>=0; d--){
            int r = cells[d][0]-1, c = cells[d][1]-1;
            int cur = r*col+c;            
            uf[r*col+c] = -1;
            for ( int i=0; i<4; i++){
                int r1 = r + dir[i] , c1  = c + dir[i+1];
                if ( r1 >=0 && r1<row && c1 >=0 && c1 <col && uf[r1*col + c1] >= -1){
                    int n1 = find(r1*col+c1);
                    if(n1 != cur){
                        uf[max(cur,n1)] = min(cur,n1);
                        cur = min(cur,n1);
                    }
                }
            }
            
            if (cur < col)
                for(int j = 0; j<col; j++){
                    if (find((row-1) * col +j) < col){
                        return d;
                    }
                }
        }
        return -1;
    }
};