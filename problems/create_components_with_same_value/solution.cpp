class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int N =  nums.size(), _max=1e6;
        vector<vector<int>> G(N);
        for (auto &e: edges)
            G[e[0]].push_back(e[1]), G[e[1]].push_back(e[0]);
        
        int sum = accumulate(begin(nums),end(nums),0);

        function<int(int,int,vector<int>&)> dfs = [&](int u, int t, vector<int>& cnt2){
            cnt2[u] = nums[u];

            for (auto v : G[u]){
                 if (cnt2[v]) continue;
                 cnt2[u] += dfs(v,t,cnt2);
                 if (cnt2[u] > t) return _max;
            }
            return cnt2[u]==t ? 0 : cnt2[u];
        };
        
        for (int i=N; i>1; i--){
            
            if (sum%i ==0 ){
                vector<int> cnt1(N);
                if ( dfs(0,sum/i, cnt1)==0)                
                 return i-1;
            }
        }
        return 0;
    }
};