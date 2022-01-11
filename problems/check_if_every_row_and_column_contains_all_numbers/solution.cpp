class Solution {
public:
    bool checkValid1(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = n;
        for (int j=1; j<n; j++) m ^= j;
        for (int j=0; j<n; j++){
            int r=0,c=0;
            for (int i=0; i<n; i++){
                r ^=  (matrix[i][j]);
                c ^=  (matrix[j][i]);
            }    
            if (r != c || r != m ) return false;
        }
        return true;
    }
    bool checkValid(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        
        for (int j=0; j<n; j++){
            bitset<101> r,c;
            for (int i=0; i<n; i++){
                r[matrix[i][j]] = c[matrix[j][i]] =1;
            }    
            if (r.count() != n || c.count() != n ) return false;
        }
        return true;
    }    
};