class Solution {
public:
    int dp[256], M,N;
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<int> s,m;
        M = students.size();
        N = students[0].size();
        memset(dp,-1,sizeof(dp));
        
        for (auto v : students){
            int n=0;
            for (auto d : v) n = (n<<1) | d;
            s.push_back(n);
        }
        for (auto v : mentors){
            int n=0;
            for (auto d : v) n = (n<<1) | d;
            m.push_back(n);
        }   

        return backtrack(s,m,0,0);
    }

    int backtrack(vector<int>& s, vector<int>& m, int i, int mask){
        if (i == M)  return 0;
        if (dp[mask] !=-1) return dp[mask];
        int ans =0 ;
             
        for (int j =0; j<M; j++)
            if ((mask & 1 << j) == 0)
                ans = max (ans, cal(s,m,i,j) + backtrack(s,m, i+1, mask|1 << j));     

        return dp[mask] = ans;
    }
    int cal(vector<int>& s, vector<int>& m, int i, int j){
        int n = s[i] ^ m[j], cnt=0;
        if (n==0) return N;
        while (n){
            cnt++;
            n &= n-1; 
        }
        return N-cnt;
        
    }

};