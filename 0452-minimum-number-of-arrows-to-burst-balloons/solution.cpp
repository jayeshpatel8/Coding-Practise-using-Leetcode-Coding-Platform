class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points),end(points),[&](auto & a, auto & b){ return a[1] < b[1];});
        
        int end=points[0][1], ans = 1;
        
        for (int i=1; i<points.size(); i++){
            if (points[i][0] <= end) continue;
            ans++;
            end = points[i][1];
        }
        return ans;
    }
};

// 6 6 5 5
// [7,12]  [2,6]
// [2,2] [4,4]
