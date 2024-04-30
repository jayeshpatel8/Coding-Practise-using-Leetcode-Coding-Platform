
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int m = matrix.size(),n=matrix[0].size(),max1=0;
        vector<int> height(n,0),r(n,n),l(n,0);
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
                if (matrix[i][j]=='1') height[j]+=1;
                else height[j]=0;
            int left =0;
            for (int j=0; j<n; j++)
                if (matrix[i][j]=='1') l[j]=max(l[j],left);
                else {l[j]=0; left=j+1;};
            int right=n;
            for (int j=n-1; j>=0; j--)
                if (matrix[i][j]=='1') r[j]=min(r[j],right);
                else {r[j]=n; right=j;};                
            for (int j=0; j<n; j++)
                max1 = max(max1,(r[j]-l[j])*height[j]);
         
        }
    return max1;
    }
};
