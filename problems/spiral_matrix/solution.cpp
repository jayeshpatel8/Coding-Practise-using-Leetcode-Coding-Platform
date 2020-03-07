
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> o;
        int r=matrix.size(),c;
        if (!r) return o;
        
        c=matrix[0].size();cout << r << c ;
        int x[4]={0,1,0,-1};
        int y[4]={1,0,-1,0};
        int dir=0;
        int step[2]={c,r-1};
        int row=0,col=-1;
        while(step[dir%2]){                    
            for (int i=0; i<step[dir%2];i++)
            {
                row+=x[dir];col+=y[dir];
                o.push_back(matrix[row][col]);
            }
            step[dir%2]--;
            dir = (dir+1)%4;
        }
      return o;
    }
};