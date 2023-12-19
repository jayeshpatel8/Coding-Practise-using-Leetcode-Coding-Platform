class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans(img);
        int M = img.size(), N = img[0].size();

        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                int c = 0,sum=0;
                for(int i1=max(0,i-1), M1=min(M,i+2); i1<M1; i1++ ){
                    for(int j1=max(0,j-1), N1=min(N,j+2); j1<N1; j1++ ){
                        sum += img[i1][j1];c++;
                    }
                }
                ans[i][j] = sum/c;
            }
        }
        return ans;

    }
};
