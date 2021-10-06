class Solution {
public:
    int dp[101][101]={};
    vector<vector<int>> costs;
    int minDistance(vector<int>& h, int k) {
        sort(begin(h), end(h));
        costs.resize(h.size(), vector<int>(h.size()));
        for (int i=0; i<h.size(); i++){
            for (int j=i; j<h.size(); j++){
                int mid_old = h[(i + j - 1) / 2], mid_new = h[(i + j) / 2];
                costs[i][j] = (j == 0 ? 0 : costs[i][j - 1]) + 
                    h[j] - mid_new + (mid_new - mid_old) * (j - i) % 2;                
                /*
                int mid = h[(i+j) / 2];
                for(int p = i; p<=j; p++){
                    costs[i][j] +=abs(mid - h[p]);
                } */               
            }
        }
        return dfs(h,0,k);
    }
    int dfs(vector<int>& h, int start, int k){
        if (start >= h.size() || k<=0) return (start == h.size() && k==0) ? 0 : 1e7;
        if (dp[start][k]) return dp[start][k];
        int ans = 1e7;
        for (int i=start; i<=h.size()-k; i++){            
            ans = min(ans, costs[start][i] + dfs(h,i+1,k-1));
        }
        return dp[start][k] = ans;
    }
    /*
    int dp[101][101][101]={};
    int minDistance(vector<int>& houses, int k) {
        sort(begin(houses), end(houses));
        return dfs(houses,0,0,k);
    }
    int dfs(vector<int>& h, int start, int end, int k){
        if (end >= h.size() || k<=0) return (end == h.size() && k==0) ? 0 : INT_MAX;

        if (dp[start][end][k]) return dp[start][end][k];
        int ans = dfs(h,end+1, end+1, k-1);
        if (ans != INT_MAX){
            int mid = h[(end+start) / 2];
            for(int p = start; p<=end; p++){
                ans +=abs(mid - h[p]);
            }
        }
        ans = min(ans, dfs(h,start, end+1, k));
        
        return dp[start][end][k] =ans;
        
    }*/
};