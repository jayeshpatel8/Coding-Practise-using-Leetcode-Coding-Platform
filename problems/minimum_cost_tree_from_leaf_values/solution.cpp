class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> stack;
        stack.push_back(INT_MAX);
        int ans=  0;
        for (int i=0; i<arr.size(); i++){
            int cur = arr[i];
            while(stack.back() < cur){
                int rem = stack.back(); stack.pop_back();
                ans += rem * min(cur, stack.back());
            }
            stack.push_back(cur);
        }
        for(int i=2; i<stack.size(); i++)
            ans += stack[i] * stack[i-1];
        return ans;
    }
    /* O(N ^ 3)
    pair<int,int> dp[41][41];
    int mctFromLeafValues(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        return dfs(arr,0,arr.size()-1).second ;
    }
    pair<int,int> dfs(vector<int>& arr, int s, int e){
        if (s == e) return {arr[s],0};
        if(dp[s][e].first != -1) return dp[s][e];
        if(s +1 ==e) return dp[s][e] = {max(arr[s] , arr[e]),arr[s] * arr[e]};
        int ans = INT_MAX, me = 0;
        for (int i=s; i<e; i++){
            pair<int,int> a  = dfs(arr,s,i), b = dfs(arr,i+1,e);
            int sum = a.first * b.first + a.second + b.second;
            if (ans > (sum)){
                me = max(a.first, b.first);
                ans = sum;
            }
        }
        return dp[s][e] = {me,ans};
    }*/
};