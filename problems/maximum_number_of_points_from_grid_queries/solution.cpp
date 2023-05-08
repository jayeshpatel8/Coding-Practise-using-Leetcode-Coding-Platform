class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int k = queries.size(), M=grid.size(),N=grid[0].size();
        vector<int> ids(k), ans(k);
        iota(begin(ids),end(ids),0);
        sort(begin(ids),end(ids),[&](auto a, auto b){ return queries[a] < queries[b];});
        int dirs[5] = {-1,0,1,0,-1};
        using ar = array<int,3>;
        priority_queue<ar,vector<ar>, greater<>> pq;
        pq.push({grid[0][0],0,0});
        grid[0][0]=0;
        int cnt = 0;
        
        for (auto i : ids){
            int q = queries[i];
            while (!pq.empty()){
                auto [v,r,c] = pq.top();
                if (q <= v )break;
                pq.pop();
                cnt++;
                for (int d=0; d<4; d++){
                    int r1 = r + dirs[d], c1 = c + dirs[d+1];
                    if (r1>=0 && c1 >= 0 && r1 <M && c1<N && grid[r1][c1]){
                        pq.push({grid[r1][c1],r1,c1});
                        grid[r1][c1]= 0;
                    }
                }
             
            }
            ans[i]=cnt;
             
        }
        return ans;
    }
};