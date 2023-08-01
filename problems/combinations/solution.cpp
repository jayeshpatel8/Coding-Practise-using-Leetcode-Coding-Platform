class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    int N;
    vector<vector<int>> combine(int n, int k) {
        N=n;
        dfs(1,k);
        return ans;
    }
    void dfs(int i, int k){

        if (k==0){            
            ans.push_back(cur);
            return;
        }
        for (int j=i; j<=N; j++){
            cur.push_back(j);
            dfs(j+1,k-1);
            cur.pop_back();
        }
        
    }
};