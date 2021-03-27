#define PA 1
#define AT 2

class Solution {
public:
    
    int dp[201][201],m,n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        m = h.size(), n= h[0].size();
       
        memset(dp,0,sizeof(int)*m*n);
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++) 
                if(i==0 || j==0)
                    DFS_p(h,i,j,0,PA);

        for (int i=m-1; i>=0; i--)
            for (int j=n-1; j>=0; j--) 
                if(i==m-1 || j==n-1)
                    DFS_p(h,i,j,0,AT);
        
        vector<vector<int>> ans;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if(dp[i][j] > AT)
                    ans.push_back({i,j});

            
        return ans;
    }
    void DFS_p(vector<vector<int>>& h, int i, int j, int p,int k){
        
        if  (i<0 || j<0  || i>=m || j>= n || p>h[i][j] || dp[i][j]>=k) return;
        
        dp[i][j]+=k;
        p  = h[i][j];
        DFS_p(h,i,j+1,p,k);
        DFS_p(h,i+1,j,p,k);
        DFS_p(h,i-1,j,p,k);
        DFS_p(h,i,j-1,p,k);        
    }  
};
#if 0
class Solution {
public:
    
    int dp[201][201],m,n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        m = h.size(), n= h[0].size();
       
        memset(dp,0,sizeof(int)*m*n);
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++) 
                if(i==0 || j==0)
                    DFS_p(h,i,j,0,PA);

        for (int i=m-1; i>=0; i--)
            for (int j=n-1; j>=0; j--) 
                if(i==m-1 || j==n-1)
                    DFS_p(h,i,j,0,AT);
        
        vector<vector<int>> ans;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if(dp[i][j] > AT)
                    ans.push_back({i,j});

            
        return ans;
    }
    void DFS_p(vector<vector<int>>& h, int i, int j, int p,int k){
        
        if  (i<0 || j<0  || i>=m || j>= n || p>h[i][j] || dp[i][j]>=k) return;
        
        dp[i][j]+=k;
        p  = h[i][j];
        DFS_p(h,i,j+1,p,k);
        DFS_p(h,i+1,j,p,k);
        DFS_p(h,i-1,j,p,k);
        DFS_p(h,i,j-1,p,k);        
    }
    void DFS_a(vector<vector<int>>& h, int i, int j, int p){
       
        if  (i<0 || j<0  || i>=m || j>= n ||p>h[i][j] || dp[i][j]>=2) return;
       
        dp[i][j]+=2;
        p  = h[i][j];
        DFS_a(h,i-1,j,p);
        DFS_a(h,i,j-1,p);
        DFS_a(h,i,j+1,p);
        DFS_a(h,i+1,j,p);        
    }    
};
#endif