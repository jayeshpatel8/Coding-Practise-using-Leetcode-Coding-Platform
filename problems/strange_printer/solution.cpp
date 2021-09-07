class Solution {
public:
    int dp[101][101]={};
    int strangePrinter(string s1) {
        string s(1,s1[0]);
        for ( int i=1;i<s1.size(); i++){
            if (s1[i]==s1[i-1])continue;
            s.push_back(s1[i]);
        }
        return dfs(s,0,s.size()-1);
    }
    int dfs(string & s, int start, int end){
        if(start >= end) return start == end;
        if(dp[start][end]) return dp[start][end];
        int len=end-start,ans = dfs(s,start+1,end)+1;
        
        for ( int k=start+1; k<=end; k++){
            if (s[start]==s[k])
            //ans = min (ans, dfs(s,start,k-1)+dfs(s,k,end)-1);
            ans = min (ans, dfs(s,start+1,k-1)+dfs(s,k,end));
            //if (ans == 1) break;
        }
        return dp[start][end] = ans;
    }
}; 