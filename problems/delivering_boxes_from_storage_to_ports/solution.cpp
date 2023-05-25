class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int mb, int mw) {
        int m = boxes.size();
        vector<int> dp(m+1);
  
        int cost = 1, w = 0;
        for (int i=0,j=0; i<m; i++){
            if (i==0 || boxes[i-1][0]  != boxes[i][0]) cost++;

            w+=boxes[i][1];

            while (i-j +1 > mb || w > mw || (j<i && dp[j+1]<=dp[j])){
                w-=boxes[j][1];
                if (boxes[j][0]  != boxes[j+1][0]) cost--;
                j++;
            }
            dp[i+1] = dp[j] + cost;
        }
        
        return dp[m];
    }
};