class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int l = 0, r= 1e6;
        while (l<r){
            int m = l + (r-l)/2;
            auto c = check(heights,m);
            if (c <= m)
                r = c;
            else
                l= m+1;
        }
        return r;
    }
    int dirs[5]={-1,0,1,0,-1};
    int check(vector<vector<int>>& hs, int k){
        int n= hs.size(),m = hs[0].size();
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> pq;
        
        vector<vector<bool>> seen(n, vector<bool>(m, false));
        pq.push({0,0});
        seen[0][0]=true;
       int best=0;
        while (!pq.empty()){
            auto  i = pq.top(); pq.pop();            
            
            int r = i[0], c = i[1];
            if (r==n-1 && c==m-1) return best;
            for (int j=0; j<4; j++){
                auto r1= r+dirs[j] ,c1 = c+dirs[j+1];
                if (r1<0 || r1>=n || c1<0 ||c1>=m || seen[r1][c1]) continue;
                auto diff = abs(hs[r][c] - hs[r1][c1]);
                if (k < diff ) continue;
                best= max(best,diff);
                seen[r1][c1] =true;
                pq.push({r1 , c1});
            }
        }
        return k+1;
    }
};