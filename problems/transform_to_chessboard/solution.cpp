class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int  N = board.size();
        int r1cnt=0,c1cnt=0,rswap=0,cswap=0;
        for (int i=0; i<N; i++){
            for(int j = 0; j<N; j++)
                if (board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) return -1;
            r1cnt += board[0][i];
            c1cnt += board[i][0];
            rswap += board[i][0] == (i%2);
            cswap += board[0][i] == (i%2);
        }
        if (r1cnt != N/2 && r1cnt != (N+1)/2) return -1;
        if (c1cnt != N/2 && c1cnt != (N+1)/2) return -1;
        if(N%2){
            if(rswap % 2)
                rswap = N-rswap;
            if (cswap % 2)
                cswap= N-cswap;
        }
        else
            rswap = min(N-rswap,rswap), cswap= min(N-cswap,cswap);
        return (rswap+cswap) / 2;
    }
};