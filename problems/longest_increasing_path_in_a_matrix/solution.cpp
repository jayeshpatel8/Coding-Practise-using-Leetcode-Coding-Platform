class Solution {
public:
    int m,n;
    int dp[200][200];
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         m =  matrix.size();
        n=matrix[0].size();
             int ans=0;
       memset(dp,0,sizeof(dp));
        for (int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = max (ans, lip(matrix,i,j));               
            }
        }
        return ans;
    }
    int lip(vector<vector<int>>& matrix, int i, int j){
               
        if ( matrix[i][j] < 0 ) return 1;
        if ( dp[i][j]!=0) return  dp[i][j];
         int prev = matrix[i][j];
        matrix[i][j]= -1;
        int ans=1;
        
        if ((i+1 <m )&& prev < matrix[i+1][j] ) 
            ans = max (ans ,  1 + lip(matrix,i+1,j));
        
        if ((j+1 <n) && prev < matrix[i][j+1] ) {
                    ans = max (ans ,  1 + lip(matrix,i,j+1));
        }
        if (i-1 >=0 && prev < matrix[i-1][j] ) ans = max (ans ,  1 + lip(matrix,i-1,j));
        if (j-1 >=0 && prev < matrix[i][j-1] ) ans = max (ans ,  1 + lip(matrix,i,j-1));
        
        matrix[i][j]= prev;
        
        return dp[i][j]= ans;
    }
};