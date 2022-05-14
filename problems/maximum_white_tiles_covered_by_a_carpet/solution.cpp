class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int len) {
        sort(begin(tiles),end(tiles));
        long long start=tiles[0][0],end=0, ans = 0, l = 0;
        for (int i=0,j=0; i<tiles.size()&& j<tiles.size(); ){
               if (start + len -1 >= tiles[j][1]) {
                   l += tiles[j][1] - tiles[j][0] +1 ;
                   j++;
                   ans= max(ans, l);
               }
                else{
                   ans = max(ans, l + start + len - tiles[j][0]);
                    if (i < j)
                        l -= tiles[i][1] - tiles[i++][0] +1;
                    
                    start =tiles[i][0];
                }
        }
        return ans;
    }
};