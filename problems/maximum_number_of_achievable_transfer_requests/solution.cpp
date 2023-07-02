class Solution {
public:
int deg[21]={};
    int maximumRequests(int n, vector<vector<int>>& req,int  i= 0) {
        if (i >= req.size()){
            return count(begin(deg),begin(deg)+n,0) ==n ? 0 : INT_MIN;
        }    
        int ans = maximumRequests(n,req,i+1);
        int u = req[i][0] ,v = req[i][1];
        deg[u]--;
        deg[v]++;
        ans= max(ans, 1 + maximumRequests(n,req,i+1));
        deg[v]--;
        deg[u]++;
        return ans;
    }
};