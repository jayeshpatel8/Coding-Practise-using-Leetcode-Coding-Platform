class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& co) {
     auto X = (co[0][0] - co[1][0]);
     auto Y = (co[0][1] - co[1][1]);
        // slope DeltY / DeltaX
        // same line => DY1/DX1 == DY2/DX2
        //           => DY1 * DX2  == DY2 * DX1
        for ( int  i=2;  i<co.size(); i++){
            if (Y * (co[0][0] - co[i][0]) !=  X * (co[0][1] - co[i][1])) return false;
        }
        return true;
    }
};