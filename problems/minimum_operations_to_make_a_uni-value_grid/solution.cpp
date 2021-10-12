class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int M = grid.size(), N = grid[0].size();
        vector<int> A(M*N);
        int k=0;
        for (auto i : grid){
            for (auto j : i)
            {
                A[k++]=j;               
            }
        }
        sort(begin(A),end(A));
        int m =  A[(A.size()-1)/2],ans=0;
        for (auto i : A){
            if (m != i){
                int diff = abs(i-m);
                if (diff%x) return -1;
                ans +=diff/x;
            }
        }  
        return ans;
    }
};