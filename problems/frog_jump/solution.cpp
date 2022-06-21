class Solution {
public:
    unordered_map<long,bool> dp;
    unordered_map<int,int> map;
    bool canCross(vector<int>& stones) {
        for (int i=0; i<stones.size(); i++) map[stones[i]] = i;
        return dfs(stones,0,0);
    }
    bool dfs(vector<int>& stones, int i, int k){
        if (i >= stones.size()-1) return true;
    
        long idx = k<<20 | i ;
        auto it = dp.find(idx);
        if (it != end(dp)  ) return it->second;
        
        for (int s=max(stones[i]+1,stones[i]+k-1)  ;  s<= stones[i]+k+1; s++){
            auto it = map.find(s);
            if (it == end(map)) continue;
            if (dfs(stones, it->second, s-stones[i]))
                return dp[idx] = true;            
        }
        return dp[idx]=false;
    }
};