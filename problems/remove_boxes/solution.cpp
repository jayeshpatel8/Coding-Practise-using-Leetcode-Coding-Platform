class Solution {
public:
    int dp[100][100][100];
    int removeBoxes(vector<int>& boxes) {
        memset(dp,-1,sizeof(dp));
        return count(boxes,0, boxes.size()-1,0);
    }
    int count(vector<int> & boxes, int i, int j, int k){
        if(i>j) return 0;
        if (dp[i][j][k] != -1) return dp[i][j][k];
        int nexti = i+1, cnt = k;
        while (nexti <= j){
            if (boxes[nexti] != boxes[i]) break;
            nexti++;cnt++;
        }
        int ans = (cnt+1)*(cnt+1) + count(boxes, nexti,j,0);
        for (int m=nexti; m<=j; m++){
            if (boxes[i] == boxes[m]){
                ans = max(ans, count(boxes, nexti,m-1,0) + count(boxes, m,j,cnt+1));
              
            }
        }
        return dp[i][j][k] = dp[nexti-1][j][cnt] = ans;
    }
};