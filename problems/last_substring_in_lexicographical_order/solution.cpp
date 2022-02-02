class Solution {
public:
    string lastSubstring(string s) {
        int  N = s.size(), i=N-2,j=N-1;
        for (; i>=0; i--){
            if (s[i] > s[j]) j = i;
            else if (s[i] == s[j]){
                int k = 1,e = min(j-i,N-j);
                while (k<e){                    
                    if (s[i+k] == s[j+k]){
                        k++; continue;   
                    }
                    break;
                }
                if (k==e || s[i+k] > s[j+k]) j = i;                
            }
        }
        return s.substr(j);
    }
};