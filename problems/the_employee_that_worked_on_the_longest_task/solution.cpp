class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans =logs[0][1], j = logs[0][0];
        for (int i=1; i<logs.size(); i++){
            int m = -logs[i-1][1]+ logs[i][1];
            if (ans <= m){
                if ( ans != m || j > logs[i][0])
                    j = logs[i][0];

                ans=m;
            }
        }

        return j;
    }
};