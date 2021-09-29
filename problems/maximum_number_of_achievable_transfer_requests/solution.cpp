class Solution {
public:
    int degree[21]={}, N, ans = 0, n1 ;
    int maximumRequests(int n, vector<vector<int>>& requests) {
        N = requests.size();
        n1 = n;
        return dfs(requests);
    }
    int dfs(vector<vector<int>>& req, int i=0){
        if(i>=N){
            return (count(begin(degree), begin(degree) + n1, 0) == n1) ? 0 : INT_MIN;
        }
        int ans =  dfs(req,i+1);
        degree[req[i][0]]++;
        degree[req[i][1]]--;
        ans = max(ans, 1 + dfs(req,i+1));
        degree[req[i][1]]++;
        degree[req[i][0]]--;
        return ans;
    }
};