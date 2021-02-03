class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        int pal[n+1];
        for (int i=0; i<=n; i++) pal[i]=i-1;
        
        //aabba
        for (int L=0; L<n; L++){
            
            bool pal1 = true,pal2=true;
            for (int i=L, j =L,k=L+1; i>=0 && j<n && (pal1 || pal2); i--,j++){
                if (pal1 && s[i] == s[j])
                    pal[j+1] = min(pal[j+1], 1 + pal[i]);
                else pal1=false;
                if (pal2 && k<n && s[i] == s[k])
                    pal[k++ +1] = min(pal[k+1], 1 + pal[i]);                
                else pal2=false;
            }
        }
          return pal[n];      
    }
};