class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        if (moves.size() < 3) return "Pending";
        int m[3][3], j = 1;
        memset(m,-1,sizeof(m));
        
        for (auto i : moves){
            m[i[0]][i[1]]= j++%2;

            for ( int i=0; i<3; i++)
                if (m[i][0]!=  -1 && m[i][0] ==  m[i][1] && m[i][0] == m[i][2]) {
                    return m[i][0] == 1 ? "A" : "B";
                }

            for ( int j=0; j<3; j++)
                if (m[0][j] != -1 && m[0][j] ==  m[1][j] && m[0][j] == m[2][j]) return m[0][j] == 1 ? "A" : "B";        

            if (m[0][0] != -1 &&  m[0][0] == m[1][1] && m[0][0] == m[2][2]) return m[0][0] == 1 ? "A" : "B";

            if (m[0][2] != -1 && m[0][2] == m[1][1] && m[0][2] == m[2][0]) return m[0][2] == 1 ? "A" : "B";
        }
        if (moves.size() < 9) return "Pending";
        return "Draw";
    }
};