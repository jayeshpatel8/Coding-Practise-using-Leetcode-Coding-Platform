class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int n = s.size();
        for (int i=n-1; i>=0; i--){
                
            while (++s[i] < 'a'+k)
            { 
                if (i-1>=0 && s[i-1]==s[i]) continue;
                if (i-2>=0 && s[i-2]==s[i]) continue;
                break;
            }
            if (s[i]=='a'+k) continue;
            i++;
            for (;i<n; i++){ 
                for(int c='a'; c<'a'+k; c++){                    
                    if (i-1>=0 && s[i-1]==c) continue;
                    if (i-2>=0 && s[i-2]==c) continue;
                    s[i]=c;
                    break;
                }                
            }
            return s;
        }
        return "";
    }
};