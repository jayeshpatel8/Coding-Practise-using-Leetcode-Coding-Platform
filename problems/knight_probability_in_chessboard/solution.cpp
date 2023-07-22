
class Solution {
public:
    double  DP[25][25][101]={};
    double knightProbability(int N, int K, int r, int c) {
        return kp( N,  K, r, c)     ;
    }
    double kp(int N, int K, int r, int c)     {
        if(r<0 || r>=N || c<0 || c>=N)
            return 0.0;
        if(K==0)
            return 1.0;
        if(DP[r][c][K]>0)
            return DP[r][c][K];
        K--;
        double res=kp( N,  K, r-2,c-1);        
        res+=kp( N,  K, r-2,c+1);
        res+=kp( N,  K, r+2,c-1);
        res+=kp( N,  K, r+2,c+1);
        res+=kp( N,  K, r+1,c+2);
        res+=kp( N,  K, r-1,c+2);        
        res+=kp( N,  K, r+1,c-2);
         res+=kp( N,  K, r-1,c-2); 
        K++;
        return   DP[r][c][K]=res/8.0;
    }
};