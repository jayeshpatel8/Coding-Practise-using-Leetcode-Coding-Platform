class Solution {
public:
    int K,N;
    int vis[12]={};    
    int res=0;
    int minimumTimeRequired(vector<int>& jobs, int k) {
        K=k;
        N = jobs.size();
        if (N<=K) return *max_element(jobs.begin(), jobs.end());
        sort(jobs.begin(), jobs.end(), greater<int>());
        for (int i = 0; i < N; i += k)
            res += jobs[i];        
        minTR(jobs,0,0);
        return res; 
    }
    // [1,2,4,7,8], k = 2
    int minTR(vector<int>& jobs,int j, int cur){
        if (cur >= res) return res;
        if (j>= N) return res = cur;
        
        unordered_set<int> cache;
        for (int k=0; k<K; k++){
            if (cache.insert(vis[k]).second){
                vis[k] += jobs[j];
                minTR(jobs,j+1,max(cur,vis[k]));
                vis[k] -= jobs[j];
            }
        }
        return res;
    }
};