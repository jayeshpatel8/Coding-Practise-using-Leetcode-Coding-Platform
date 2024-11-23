class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int M = box.size(), N = box[0].size();
        for (auto &r : box){
            for (int c1=N-1,c2=N-1; c1>=0; c1--){
                if (r[c1]=='*')c2=c1-1;
                else if (r[c1]=='#') {
                    r[c2]=r[c1];
                    if (c1 != c2) 
                        r[c1]='.';
                    c2--;
                }
            }
        }
        vector<vector<char>> ans (N,vector<char>(M));
        for (int r=0; r <M; r++){
            for (int c=0; c<N; c++){
                ans[c][M-r-1]=box[r][c];
            }
        }
        return ans;
    }
};
