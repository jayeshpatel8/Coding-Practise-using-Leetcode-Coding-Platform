class Solution {
public:
    string subStrHash(string s, int p, int m, int k, int hs) {
        int N = s.size();
        long ans = 0, p1 = 1;        
        for (int j = N-1; j>N-k-1; j--){
            ans = ((ans * p ) + (s[j]-'a'+1))%m ;
            p1 = (p1*p)%m;                    
        }        
        int a1 = N;
        if (ans == hs) a1 = N-k;
        for (int i=N-1, j =N-k-1;j>=0; i--,j--){
            {
                ans = (ans * p  + ((s[j]-'a'+1) ))%m;
                ans  -= ( (s[i]-'a'+1)* p1) % m;
                if (ans < 0) ans += m;
                
                if (ans == hs) a1 = j;                
            }
        }
        return a1 != N ? s.substr(a1,k) : s.substr(a1,0);
    }
};