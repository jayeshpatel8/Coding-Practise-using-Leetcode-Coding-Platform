class Solution {
public:
    int dp[100][100];
    int N;
    int findRotateSteps(string ring, string key) {
        N = ring.size();
        memset(dp,-1,sizeof(dp));
        return steps(ring,key);
    }
    int steps(string & ring, string & key, int cur = 0, int  i=0){
        if (i == key.size()) return 0;
        if(dp[i][cur] != -1) return dp[i][cur];
        int ans=INT_MAX;
        for (int j = 0; j < ring.size(); j++) {
            if (ring[j] == key[i]) {
                int step = max(cur, j) - min(cur, j);
                step = min(step, (int)(ring.size() - step));
                ans = min(ans, step + 1 + steps(ring, key, j, i + 1));
            }       
        }
        return dp[i][cur] = ans;
    }
};

/*

int helper(string &ring,string &key,int n,int m,int i,int prev){
	if(i==m)return 0;
	
	if(dp[i][prev]!=-1)return dp[i][prev];
int ans=10000;
	for(int k=0;k<n;k++){
		if(ring[k]==key[i]){
			ans=min(ans,1+helper(ring,key,n,m,i+1,k)+min(abs(prev-k),n-abs(prev-k)));
		}
}
	return dp[i][prev]=ans;
}

*/