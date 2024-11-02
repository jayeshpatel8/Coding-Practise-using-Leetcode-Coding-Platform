
        

class Solution { public: bool isCircularSentence(string s) { int i=0, N=s.size(),prev = N-1; if (s[i] !=s[prev]) return false; for (int j=0; i<N; i+=1){ if (s[i] != ' ') continue; if (s[i-1] != s[i+1]) return false; i++; } return true; } };
