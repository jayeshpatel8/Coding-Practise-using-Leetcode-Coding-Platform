class Solution {
public:
    int cl=0,fsz;
    vector<int> psum;
    //int dp[1001][1001];
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int l = numCarpets *  carpetLen;
        fsz = floor.size();
        if (l >= fsz) return 0;
        cl = carpetLen;
        //memset(dp,-1,sizeof(dp));
        psum.resize(fsz+1);
        int total=0,j=1;
        for (auto &i : floor) {
            total += i=='1';
            psum[j++]=total;
        }
        if (cl == 1) return max(0,total-l);
        if (total == fsz) return max(0,total - l);
        
        vector<vector<int>> dp(fsz, vector<int>(numCarpets + 1,-1));
        return total - dfs(floor, 0, numCarpets,dp);

    }
    int dfs(string &floor, int i, int nc,vector<vector<int>>&dp){
        if (i >=fsz || nc == 0) return 0;
        if (dp[i][nc] != -1) return dp[i][nc];
        if (fsz - i <= nc * cl ) return dp[i][nc] = psum[fsz] -psum [i];
        int ans = dfs (floor,i+1,nc,dp); 
        
        if (floor[i] == '1')
         ans =max(ans,  psum[min(i+cl,fsz)] -psum [i] + dfs(floor, i+cl,nc-1,dp));        
        
        return dp[i][nc] = ans;;
    }
};

