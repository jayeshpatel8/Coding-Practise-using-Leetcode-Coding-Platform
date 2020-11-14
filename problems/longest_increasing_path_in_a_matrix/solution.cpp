#include <bits/stdc++.h>
class Solution {
public:
    //unordered_map<string,int> dict;
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m <1) return m;
        
        int n = matrix[0].size();
        vector<vector<int>> R (m,vector<int>(n,-1));
        int r=0;
        
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++)
            {
                r = max(r,longestIncreasingPath(matrix,i,j,m,n,R));
            }
         }
        return r;
    }
    int longestIncreasingPath(vector<vector<int>>& M, int i, int j, int m, int n,vector<vector<int>>& R){
            
        
        if (R[i][j] != -1 ) return R[i][j];
        int res=0;
        if (i+1 < m && (M[i+1][j]-M[i][j]>0) ){
            res = max(res,longestIncreasingPath(M,i+1,j,m,n,R));
        }
        if (j+1 < n && (M[i][j+1]-M[i][j]>0) ){
            res = max(res,longestIncreasingPath(M,i,j+1,m,n,R));
        }
        if (j-1 >= 0 && (M[i][j-1]-M[i][j]>0) ){
            res = max(res,longestIncreasingPath(M,i,j-1,m,n,R));
        }
        if (i-1 >= 0 && (M[i-1][j]-M[i][j]>0) ){
            res = max(res,longestIncreasingPath(M,i-1,j,m,n,R));
        }
        return R[i][j]=res+1;
    }
};