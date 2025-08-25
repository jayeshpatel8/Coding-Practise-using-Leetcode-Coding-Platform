class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int M =mat.size(), N = mat[0].size();
        bool down=0;
        for (int i=0, j=0; j<N && j>=0 && i>=0 && i<M; down = !down){
            int r=i,c=j;
            if (down){
                for (; r<M && r>=0 && c<N && c >=0; r++,c--){
                    ans.push_back(mat[r][c]);
                }
              
                if (r == M) j=c+2,i=M-1;
                else i=r,j=0;
            }
            else {
                
                for (; r<M && r>=0 && c<N && c >=0; r--,c++){
                    ans.push_back(mat[r][c]);
                }
                if (c == N) i=r+2,j=N-1;
                else i=0,j=c;             
            }
        }
        return ans;
    }
    
};
