class Solution {
public:
long dp[61][1<<16] ,mskill ,sz;
unordered_map<string,int> rq;
vector<int> ppl ,ans ;
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        memset(dp,-1,sizeof(dp));
        long i=0;
        for (auto & s : req_skills)
            rq[s] =  1u << i++;
        mskill = (1<<i)-1;
        sz = people.size();
        for (auto i=0;i< people.size(); i++){
            auto & p = people[i];
            int bits=0;
            for (auto &s : p)
                if (rq.count(s)) bits |= rq[s];
            ppl.push_back( bits);
        }
        i = dfs(0,0);
        for (int j=0; j<61; j++){
            if ( (1ul << j) & i) ans.push_back(j);
        }
        return ans;
    }
    long dfs(int i, int mask = 0){
        if (i >= sz ) return mask ==  mskill ? 0 : (1ul<<sz)-1;
        
        if (dp[i][mask] != -1) return dp[i][mask];
        long ans1 = dfs(i +1 ,mask);
         long ans2 = (mask & ppl[i] ) == ppl[i] ? (1ul<<sz)-1 : dfs(i +1 ,mask | ppl[i]) | (1ul << i);
         if (__builtin_popcountll(ans1) > __builtin_popcountll(ans2))
            return dp[i][mask] =  ans2;
        return dp[i][mask] = ans1 ;
    }
};