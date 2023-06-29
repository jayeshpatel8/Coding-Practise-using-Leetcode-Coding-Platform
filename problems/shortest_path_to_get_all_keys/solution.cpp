class Solution {
public:
    bool vis[31][31][1<<6] = {};
    int shortestPathAllKeys(vector<string>& grid) {
        int N = grid.size(), M = grid[0].size();
        int allkey=0, ans = 0;
        vector<array<int,3>> q;
        for (auto i=0; i<N; i++)
            for (auto j=0; j<M; j++)
                if (islower(grid[i][j]))
                    allkey |= 1 << (grid[i][j]-'a');
                else if (grid[i][j] =='@')
                    q.push_back({i,j,0}),vis[i][j][0]=true;
        int dirs[] ={-1,0,1,0,-1};
        
        while (!q.empty()){
            vector<array<int,3>> t;
            for (auto [i,j,keys] : q ){
                if (keys == allkey) return ans;
                for (int d=  0; d<4; d++){
                    int i1=i + dirs[d],j1= j+ dirs[d+1] ,key=keys;
                    if (i1<0|| i1>=N || j1<0 ||j1>= M || grid[i1][j1]=='#' ) continue;
                    if (isupper(grid[i1][j1]) ){
                        if (!((1 << (grid[i1][j1]-'A')) & key))
                            continue;
                    }
                    else if (islower(grid[i1][j1])) key|= 1<<(grid[i1][j1]-'a');
                    if (vis[i1][j1][key]) continue;
                    vis[i1][j1][key]=1;
                    
                    t.push_back({i1,j1,key});
                }
            }
            q.swap(t);
            ans++;
        }
        return -1;
    }
};