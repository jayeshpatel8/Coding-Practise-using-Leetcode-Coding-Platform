class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans= {{rStart,cStart}};
        int len = max(rows,cols)-1;
        for (int l=1,  r =rStart, c = cStart + 1 ; l<=len; l++){
            
            for( int cnt = 0 ; cnt < 2 * l; cnt++ ){
                if (r<rows && c <cols && r>=0 && c>=0)
                    ans.push_back({r,c});
                r++; 
            }
            --r;c--;
            for( int cnt = 0 ; cnt < 2 * l; cnt++ ){
                if (r<rows && c <cols && r>=0 && c>=0)
                    ans.push_back({r,c});
                 c--;
            }            
            ++c;r--;
            for( int cnt = 0 ; cnt < 2 * l; cnt++ ){
                if (r<rows && c <cols && r>=0 && c>=0)
                    ans.push_back({r,c});
                --r;
            }                      
            ++c;r++;
            for( int cnt = 0 ; cnt < 2 * l; cnt++ ){                
                if (r<rows && c <cols && r>=0 && c>=0)
                    ans.push_back({r,c});
                c++;
            }                       
        }
        return ans;
    }
};
