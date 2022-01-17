class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(begin(points),end(points));
        int start = points[0][0], ans=0;;
        for (int i=1; i<points.size(); i++){
            if (start == points[i][0]) continue;
            ans = max(ans, points[i][0] - start);
            start = points[i][0] ;
        }
        return ans;
    }
};
