class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, priority_queue<int,vector<int>,greater<int>>> A;
        for ( int i=0;i<mat.size(); i++)
            for (int j=0;  j<mat[0].size(); j++)
                A[i-j].push(mat[i][j]);
        for ( int i=0;i<mat.size(); i++)
            for (int j=0;  j<mat[0].size(); j++){
                mat[i][j] = A[i-j].top(); A[i-j].pop();
            }
        return mat;
    }

    vector<vector<int>> diagonalSort2(vector<vector<int>>& mat) {
        vector<array<int,2>> A;
        for ( int i=0;i<mat.size(); i++)
            for (int j=0;  j<mat[0].size(); j++)
                A.push_back({i-j, mat[i][j]});
        sort(begin(A),end(A));
        int prev = -1000,  r = 0 , c = 0;
        for (auto a : A){
            if (prev != a[0] ) {
                prev = a[0];
                 r = a[0] <=0 ? 0 : a[0] ;
                 c = a[0] <=0 ? (-1* a[0]) : 0 ;
            }

            mat[r][c] = a[1];
            ++r,++c;
        }
        return mat;
    }
};