class Solution {
public:
int side;
    bool makesquare(vector<int>& ms) {
        
       side=0;
        for (auto m : ms)            side +=m;
        
        if (ms.size() < 4  || side % 4) return false;
        side /=4;
        vector<int> vis(ms.size(),0);
        sort(ms.rbegin(), ms.rend());
        return dfs(ms,0,0,4,vis);
    }
    bool dfs(vector<int>& ms, int i, int cur_sum, int k, vector<int>& vis){
        if (k == 1)             return true;
        if (cur_sum ==  side) return dfs(ms,0,0,k-1,vis);
        
        for ( int j=i; j<ms.size(); j++)
        {             
            if ( vis[j] || cur_sum + ms[j] > side) continue;
            {
                vis[j] = 1;
                if (dfs(ms,j,cur_sum + ms[j],k,vis)) return true;
                vis[j] = 0;
            }
        }
        return false;
    }
};