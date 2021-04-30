class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& rs) {
        rs.push_back({n,n-1});
        rs.push_back({1,0});
        
        sort( rs.begin(), rs.end() );
         n = rs.size();
        for (int i=1; i< n; i++){
            rs[i][1] = min(rs[i][1], rs[i-1][1] + rs[i][0] - rs[i-1][0]  );
        }
        
        for (int i=n - 2; i>=0; i--){
            rs[i][1] = min(rs[i][1], rs[i+1][1] + rs[i+1][0] - rs[i][0]  );            
        }        
        int h1,h2,ans,r,l;
        ans=0;
        for (int i=1; i<n; i++){
            l = rs[i-1][0]; r = rs[i][0];
            h1= rs[i-1][1];h2= rs[i][1];
            ans = max(ans, max(h1,h2)+(r-l - abs(h1-h2)) / 2);
        }
        return ans;
    }
};