class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n =  row * col, top= n, bottom=n+1;
        vector<int> uf(n+2,-1), sz(n+2,1);

        function<int(int)> find = [&](int i){
            return uf[i] < 0 ? i : uf[i] = find(uf[i]);
        };
        int dirs[] ={-1,0,1,0,-1};
        for (int d = n-1; d>=0; d--){
            int r = cells[d][0]-1, c = cells[d][1]-1;
            uf[r*col+c] = r==0? top : (r==row-1?bottom : -2);
             
            for (int i=0; i<4; i++){
                int r1 = r + dirs[i], c1 = c + dirs[i+1];
                if (r1<0 || c1 < 0 || r1 >= row || c1 >= col || uf[r1*col+c1]==-1) continue;
                int p2 = find(r1*col+c1),p1 = find(r*col+c);;
                if (p1!=p2){
                    if (sz[p1] > sz[p2]) swap(p1,p2);
                    uf[p2]=p1;
                    sz[p1]+=sz[p2];
                }
            }
            if (find(top) == find(bottom)) return d;
        }

        return -1;
    }
};
