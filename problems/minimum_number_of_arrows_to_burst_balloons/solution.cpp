class Solution {
public:
    int findMinArrowShots2(vector<vector<int>>& points) {
        sort(begin(points), end(points), [](auto & a, auto &b){return a[1] < b[1];});
        // put a arrow to end (x2) 
        int ans = 1, x=points[0][1];
        for ( auto & p  : points){
            if (x >= p[0]){
                continue;
            }
            else
                ans++, x=p[1];
        }
        return ans;
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points), end(points));
        // put a arrow to end (x2) 
        int ans = 1, x=points[0][1];
        for ( auto & p  : points){
            if (x >= p[0]){
                x = min(x,p[1]); // select min end of both
                continue;
            }
            else
                ans++, x=p[1];
        }
        return ans;
    }    
};
/*

[[9,12],,,[8,12],,]
[1,10][3,9][4,11][6,9],[6,7]

*/