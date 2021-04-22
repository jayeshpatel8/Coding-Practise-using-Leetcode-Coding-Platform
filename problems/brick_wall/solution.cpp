class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int max_cnt=0;
        unordered_map<int,int> m;
        for (int i=0; i < wall.size(); i++){
            int sum=0;
            for (int j=0; j<wall[i].size()-1;j++){
                sum +=wall[i][j];
                m[sum]++;
              
                max_cnt = max(max_cnt, m[sum]);
                
            }
        }
        return wall.size() - max_cnt;
    }
};