class Solution {
public:
    int minCut(string s) {
        // prepare the table for Palindrome
        int n=s.size();
        if (!n) return n;
        int Part[n+1];
        
        for (int i=0; i<=n; i++)
            Part[i] = i-1;
        
        for (int Len=0; Len<n; Len++){            
            bool pal1=true, pal2=true;    
            for ( int prev= Len , next = Len; 
                 prev>=0 && next<n && (pal1 || pal2); 
                 prev--,next++){
                
                // case: a
                if (pal1 && (s[prev] == s[next]))
                 Part[next+1] = min ( Part[next+1], 1 + Part[prev] );
                else
                    pal1=false;
                
                // case: aa
                if (pal2 && next+1<n && (s[prev] == s[next+1]))                    
                    Part[next+2] = min ( Part[next+2], 1 + Part[prev] );                    
                else
                    pal2=false;
            }
        }
        return Part[n];
  }

};