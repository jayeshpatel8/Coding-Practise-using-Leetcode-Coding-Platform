class Solution {
public:
    int M,N;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        M=matrix.size(), N=matrix[0].size();
        
        int l=matrix[0][0], r = matrix[M-1][N-1];
        while (l<r){
            int mid = (l +r)>>1;
            if (countlessAndEqual(matrix,mid) >= k){
                r = mid;
            }
            else l = mid+1;
        }
        return r;
    }
    int countlessAndEqual(vector<vector<int>>& matrix, int k){
        int ans = 0;
        for (int r=0; r<M; r++){
            int c = N-1; 
            while (c>=0 && matrix[r][c] > k) c--;
            ans += c + 1;
        }
        return ans;
    }
};