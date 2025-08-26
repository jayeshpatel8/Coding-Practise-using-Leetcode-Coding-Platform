class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        double p = 0;
        for (auto i : dimensions){
            auto j = sqrt(i[0]*i[0]+i[1]*i[1]);
            if (j>p){
                p=j;
                ans= i[0]*i[1];
            }
            else if (j==p)
                ans=max(ans, i[0]*i[1]);
        }
        return ans;
    }
};
