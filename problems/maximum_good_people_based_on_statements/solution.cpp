class Solution {
public:
    int maximumGood(vector<vector<int>>& stms) {
        int n = stms.size(), N  = (1 << n)-1;
        auto valid = [&](int stm){
            for (int i=0; i<n; i++){
                if (stm & (1 << i)){
                    for (int j=0; j<n; j++){
                        int u = (stm & (1 << j))>0, v = stms[i][j];
                        if ((u == 1 && v==0 )|| (u==0 && v==1)) return false;
                    }
                }
            }
            return true;
        };
        int ans = 0;
        for(int i=1; i<=N; i++){
            int cnt =  __builtin_popcount(i);
            if (cnt >  ans && valid(i))
                ans= max(ans,cnt);            
        }
        return ans;
    }
};