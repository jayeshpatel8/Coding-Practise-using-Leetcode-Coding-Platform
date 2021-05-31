class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis (m, vector<int>(n, 0));
        set<int> st; 
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                for ( int sz=0; i+sz<m && i-sz>=0 && j+2*sz<n; sz++){
                    int  x = i, y = j, sum = 0;
                    do sum += grid[x++][y++] ; while(x < i +sz);
                    if (sz > 0){
                        do sum += grid[x--][y++] ; while(y < j + 2 * sz);
                        do sum += grid[x--][y--] ; while(x > i -sz);
                        do sum += grid[x++][y--] ; while(x < i );
                    }
                    st.insert(sum);
                if (st.size() > 3) st.erase(begin(st));
                }
            }
        }
        return vector<int>(rbegin(st) ,  rend(st));
    }

};