class Solution {
public:
    int N;
    
    bool checkPartitioning(string s) {
        const int N=s.size();
        bool DP[2001][2001]={};
        
        for (int i=N-1; i>=0; i--){
            for (int j=i; j<N; j++){
                if (s[i]==s[j]) 
                    DP[i][j] = (i+1<=j-1) ? DP[i+1][j-1]: true;
            }
        }
        for (int j=1; j<N-1; j++){            
            if ((DP[j+1][N-1])){
                for (int i=j; i>0; i--){
                        if (DP[0][i-1] && DP[i][j]) return true;            
                }
            }
        }
        return false;
    }


};