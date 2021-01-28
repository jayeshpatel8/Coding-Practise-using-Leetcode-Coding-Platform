class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int M = matrix.size(), N = matrix[0].size();
        vector<int> res(N,0);
        for (int i=0; i<M;i++){
            for (int j=0; j<N;j++){
                if (j>0){
                    matrix[i][j] ^= matrix[i][j-1];
                }
                res[j] ^= matrix[i][j];
                pq.push(res[j]);
                if (pq.size() > k) {
                    pq.pop();
                }                
            }
        }
        //while(k-->1){pq.pop();}
        return pq.top();
    }
};