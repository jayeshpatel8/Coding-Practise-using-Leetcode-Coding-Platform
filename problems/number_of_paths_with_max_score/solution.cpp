class Solution {
public:
    int sum[101][101] = {} ,freq[101][101]={}, N, mod = 1e9 + 7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        N  =board.size();
        
        board[0][0]=board[N-1][N-1]='0';
        freq[0][0]=1;
        
        int dir [4] = {0,1,1,0};
        
        for ( int i = 1; i<= N; i++){
            for (int j=1; j<= N; j++){
                if(board[i-1][j-1] == 'X') continue;
                
                for ( int d=0; d<3; d++){                
                    int r = i - dir[d], c = j - dir[d+1];                                     
                    int v = sum[r][c] + (board[i-1][j-1]-'0');
                    if (sum[i][j] <= v && freq[r][c]  ){
                        
                        freq[i][j] = (freq[r][c] + (sum[i][j]  == v ? freq[i][j] : 0 ))%mod; 
                         sum[i][j]  = v;
                    }
                }
            }
        }
        return {freq[N][N]?sum[N][N]:0,freq[N][N]};
    }
};