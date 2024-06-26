class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(begin(points),end(points),[&](auto & a, auto &b){ return a[0] < b[0];});
        int ans=0;
        for (int i=1; i<points.size(); i++)
            ans = max(ans, points[i][0] - points[i-1][0]);
        
        return ans;
    }
};
