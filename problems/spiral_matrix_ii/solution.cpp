class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int dirs[5]={0,1,0,-1,0}, dir=0;
        int rc[2]={n,n-1},r=0,c=-1,cnt=0,j=1;
        while (rc[cnt] > 0){
            for (int i=0; i<rc[cnt]; i++){
                r += dirs[dir], c  += dirs[dir+1];
                ans[r][c]= j++;
            }
            rc[cnt]--;
            cnt=(cnt+1)%2;
            dir = (dir+1)%4;
        }
        return ans;
    }
};