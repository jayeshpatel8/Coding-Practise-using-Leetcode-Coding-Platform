class Solution {
public:
    
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        
        for (int r=rMove-1, c=cMove, cnt=1; r>=0; r--){
            if (board[r][c] == '.' ) break;
            else if( board[r][c]!= color){
                cnt++;
                
            }else if (cnt >= 2) return true;
            else break;
        }
        for (int r=rMove+1, c=cMove, cnt=1; r<8; r++){
            if (board[r][c] == '.' ) break;
            else if( board[r][c]!= color){
                cnt++;
                
            }else if (cnt >= 2) return true;
            else break;
        }
        for (int r=rMove, c=cMove+1, cnt=1; c<8; c++){
            if (board[r][c] == '.' ) break;
            else if( board[r][c]!= color){
                cnt++;
                
            }else if (cnt >= 2) return true;
            else break;
        }        
        for (int r=rMove, c=cMove-1, cnt=1; c>=0; c--){
            if (board[r][c] == '.' ) break;
            else if( board[r][c]!= color){
                cnt++;
                
            }else if (cnt >= 2) return true;
            else break;
        } 
        for (int r=rMove-1, c=cMove-1, cnt=1; r>=0 && c>=0; r--,c--){
            if (board[r][c] == '.' ) break;
            else if( board[r][c]!= color){
                cnt++;
                
            }else if (cnt >= 2) return true;
            else break;
        }  
        for (int r=rMove+1, c=cMove-1, cnt=1; r<8 && c>=0; r++,c--){
            if (board[r][c] == '.' ) break;
            else if( board[r][c]!= color){
                cnt++;
                
            }else if (cnt >= 2) return true;
            else break;
        }          
        for (int r=rMove-1, c=cMove+1, cnt=1; r>=0 && c<8; r--,c++){
            if (board[r][c] == '.' ) break;
            else if( board[r][c]!= color){
                cnt++;
                
            }else if (cnt >= 2) return true;
            else break;
        }          
        for (int r=rMove+1, c=cMove+1, cnt=1; r<8 && c<8; r++,c++){
            if (board[r][c] == '.' ) break;
            else if( board[r][c]!= color){
                cnt++;
                
            }else if (cnt >= 2) return true;
            else break;
        }          
        return false;
    }
};