class Solution {
public:
    int minOperations(string s) {
        int N=s.size();
        int DP[N+1][2];
        DP[0][0]=0;DP[0][1]=0;
        for (int i=0; i<N; i++){
            DP[i+1][0]= DP[i][1]+(s[i]=='0'?0:1);
            DP[i+1][1]=DP[i][0]+(s[i]=='1'?0:1);
        }
        
        return min (DP[N][0],DP[N][1]);    
    }
    
};

