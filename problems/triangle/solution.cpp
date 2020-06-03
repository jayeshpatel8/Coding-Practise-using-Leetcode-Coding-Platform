class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int i = triangle.size();
        if (i <2) return triangle[0][0];
        i -=2;
        int j = triangle[i].size()-1;
        for (; i>=0; i--){
            int j = triangle[i].size()-1;
            for (; j>=0; j--)
            {
                triangle[i][j] += std::min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};