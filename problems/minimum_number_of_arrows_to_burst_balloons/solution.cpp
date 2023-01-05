class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points),end(points),[&](auto &a, auto &b){return a[1] < b[1];});
        int ans = 1, end=points[0][1];
        for (auto &i : points){
            if (i[0] <= end){
                 continue;
            }
            ans++;
            end = i[1];
        }
        return ans;
    }
};