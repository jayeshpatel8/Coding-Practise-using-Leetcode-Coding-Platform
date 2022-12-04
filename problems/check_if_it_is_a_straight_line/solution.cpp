class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& co) {
     auto X = (co[0][0] - co[1][0]);
     auto Y = (co[0][1] - co[1][1]);
        auto check = [&]( int c){

            return (X * (co[1][1] - co[c][1])) == (Y *(co[1][0] - co[c][0]));
        };
        for ( int  i=2;  i<co.size(); i++){
            if (!check(i)) return false;
        }
        return true;
    }
};