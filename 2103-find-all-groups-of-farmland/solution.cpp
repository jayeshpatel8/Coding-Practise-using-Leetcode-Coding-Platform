class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;

        for ( int r = 0; r<land.size(); r++){
            for ( int c = 0; c<land[0].size(); c++){
                if (land[r][c] == 0) continue;
                int c1,r1;
                // find first zero
                for (  c1= c+1; c1<land[0].size(); c1++){
                    if (land[r][c1] == 0) break;
                    land[r][c1]=0;
                }

                for (  r1 = r+1; r1<land.size(); r1++){
                    if (land[r1][c] == 0) break;
                    for ( int c2= c; c2<c1; c2++)
                        land[r1][c2]=0;
                }          

                ans.push_back({r,c,r1-1,c1-1});
            }
        }
        return ans;
    }
};
