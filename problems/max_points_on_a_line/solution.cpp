class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n = points.size(), ans=0;
        if (n<3) return n;

        for (int i=0; i<n; i++){
            unordered_map<double,int> slop;
            for (int j=0; j<n; j++){
                if (i != j )
                    ans = max({ans, ++slop[atan2(points[j][1]-points[i][1],points[j][0]-points[i][0])]});;                
            }
        }
        return ans+1;
    }
};