class Solution {
public:
    
    int minCut(string s) {
        int N = s.size();

        vector<vector<bool>> isPal(N+1,vector<bool>(N+1,false));
        int cut[N+1];
        for (int i=0; i<=N; i++) cut[i]=i-1;        
        
        for ( int j=1; j<N; j++){
            for (int i=j; i>=0; i--){                
                if (s[i]==s[j] && (j-i < 3 || isPal[i+1][j-1]))
                    isPal[i][j]=true, cut[j+1] = min(cut[j+1],1 + cut[i]);
            }
        }
        
        return  cut[N];
    }
};