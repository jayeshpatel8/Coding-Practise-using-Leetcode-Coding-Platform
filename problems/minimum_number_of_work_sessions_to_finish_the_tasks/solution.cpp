class Solution {
public:
    int time, N, ans = 14;
    vector<int>session;
    int minSessions(vector<int>& tasks, int sessionTime) {
        time = sessionTime;
        N = tasks.size();        
        sort(tasks.begin(), tasks.end(), greater());
        dfs(tasks, 0);
        return ans;
    }
    void dfs(vector<int>& tasks, int idx=0){
        if (session.size() >= ans) return ;
        if(idx == N) {ans = session.size(); return ;}
        
        for ( int i=0, n = session.size(); i<n; i++){
            if (session[i] + tasks[idx] <= time){
                session[i] += tasks[idx];
                dfs(tasks, idx+1);
                session[i] -= tasks[idx];
            }
        }
        session.push_back(tasks[idx]);
        dfs(tasks, idx+1);
        session.pop_back();
    }
};

/*
class Solution {
public:
    int dp[1<<14][16], time, N;
    int minSessions(vector<int>& tasks, int sessionTime) {
        time = sessionTime;
        N = tasks.size();
        memset(dp,-1,sizeof(dp));
        sort(tasks.begin(), tasks.end(), std::greater());
        return dfs(tasks, 0,sessionTime);
    }
    int dfs(vector<int>& tasks, int mask, int cur ){        
        if(mask == (1<<N)-1) return 1;        
        if(dp[mask][cur] != -1) return dp[mask][cur];
        int ans = 15;
        for ( int j=0; j<N; j++){
            if (mask & (1 << j)) continue;
            if ( tasks[j]  <= cur)
                ans = min(ans, dfs(tasks, mask | (1<<j) ,  cur - tasks[j] ))  ;  
            else 
                ans = min(ans, 1 + dfs(tasks, mask | (1<<j) , time - tasks[j] ))    ;
            if (cur == time) return dp[mask][cur] = ans;
        }
        return dp[mask][cur] = ans;
    }
};
*/