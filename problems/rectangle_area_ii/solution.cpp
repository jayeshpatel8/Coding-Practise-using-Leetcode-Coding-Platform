class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int mod = 1000000000 + 7;
        set<int> xset, yset;
        
        for (auto r : rectangles) {
            xset.insert(r[0]);xset.insert(r[2]);
            yset.insert(r[1]);yset.insert(r[3]);
        }
        vector<int> x(xset.begin(), xset.end()), y(yset.begin(), yset.end());
        vector<vector<int>> visited(x.size(),vector<int>(y.size()));
        long area=0;
        for ( auto r : rectangles){
            for (auto i = lower_bound(x.begin(),x.end(),r[0]); *i!=r[2];i++)
                for (auto j = lower_bound(y.begin(),y.end(),r[1]); *j!=r[3];j++){
                    if(visited[i - x.begin()][j - y.begin()]++ ==0)
                    {
                        area = (area + (long long)(*next(i) - *i) * (*next(j) - *j)) %mod;
                    }
                }
        }
        return area;
    }
};
