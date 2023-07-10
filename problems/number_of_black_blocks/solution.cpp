class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        int ans[5] = {};
        unordered_map<long ,int> map;
        for (auto &c : coordinates){
            for (int x = max(0,c[0]-1); x <= min(c[0],m-2); x++)
                for (int y=max(0,c[1]-1); y<= min(c[1],n-2); y++)
                    map[1e5 *x + y]++;                     
        }
        for (auto & [c,v] : map)
            ans[v]++;
        return {((long)(m -1)* (n-1))-ans[1]-ans[2]-ans[3]-ans[4], ans[1],ans[2],ans[3],ans[4]};
    }
};