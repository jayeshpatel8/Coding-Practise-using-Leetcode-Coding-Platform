class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int dirs[] = {0,1,2,3};
        int cnt= n*n, i=0,j=0 ,c=0 ,r=n,d=n,l=-1,u=0,dir=0;
        vector<vector<int>> ans(n,vector<int>(n));
        while (cnt-- > 0){
            switch(dir){
                    case 0:
                        ans[i][j++]=++c; 
                        if (j==r)
                            dir=1,i++,j=j-1,r--;
                    break;
                    case 1:
                        ans[i++][j]=++c;
                        if (i==d)
                            dir=2,i=i-1,j--,d--;
                    break;
                    case 2:
                        ans[i][j--]=++c;
                        if (j==l)
                            dir=3,i--,j=j+1,l++;
                    break;
                    case 3:
                        ans[i--][j]=++c;
                        if (i==u)
                            dir=0,i+=1,j=i,u++;
                    break;
            }
        }
        return ans;
    }
};