class Solution {
public:
    map<vector<int>,int> M,dp;
    vector<int> rem;
    
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        rem.resize(batchSize,0);
        for (auto g : groups) ++rem[g % batchSize];
       
        
        return dfs( 0);
                
    }
    int dfs( int remaining ){
        if (M.count(rem)) return M[rem];
        int ans =0;
        
        for(int i=0; i<rem.size(); i++){
            if(rem[i]==0 || (rem[remaining] && i != remaining) ) continue;
            rem[i]--;
            ans =  max (ans, (remaining == 0) + dfs(  (rem.size() + remaining - i) % rem.size()));
            rem[i]++;
        }
        
        return M[rem]=ans;
    }
};