class Solution { // space O(1)
public:
    int mod = 1e9 + 7, ans=0,N;
    int numDecodings(string s) {
        N=s.size();
        
        size_t next1=1,next2=1;
        for (int i=N-1; i>=0; i--){
            int cnt=0;
            if (s[i] != '0') {
                cnt = (s[i]=='*'? (9 * next1 )%mod:  next1 ) ;
                if (i+1 < N){
                    if (s[i]=='*'){
                        if (s[i+1]=='*') cnt =( cnt + (15 * next2)%mod)%mod;
                        else cnt += (s[i+1] >'6'? next2 : (2 * next2)%mod) ;
                    }
                    else{
                        if (s[i+1]=='*') cnt += (s[i]<'3'? ((s[i]=='1'? 9 : 6) * next2)%mod :0) ;
                        else   cnt += (((s[i]-'0') * 10 + s[i+1]-'0'<27)?  next2: 0) ;
                    } 
                }         
            }
            next2=next1;
            next1=cnt %mod;
        }
        return next1 ;
    }
};

/* 
// space = O(N)
class Solution {
public:
    int mod = 1e9 + 7, ans=0,N;
    vector<int> dp;
    int numDecodings(string s) {
        N=s.size();
        dp = vector<int>(N,-1);
        int next1=s[N-1] == '*' ? 9 : s[N-1]!='0',next2=1;
        for (int i=N-2; i>=0; i--){
            
        }
        return ways(s,0);
    }
    size_t ways(string &s, int i){
        if (i == N) return 1;
        size_t cnt=0;
        if (dp[i]!=-1) return dp[i];
        if (s[i] == '0') return dp[i]= cnt;
        cnt = (s[i]=='*'? (9 * ways(s,i+1) )%mod:  ways(s,i+1) ) ;
        if (i+1 < N){
            if (s[i]=='*'){
                if (s[i+1]=='*') cnt += (15 * ways(s,i+2))%mod;
                else cnt += (s[i+1] >'6'? ways(s,i+2) : 2 * ways(s,i+2)) ;
            }
            else{
                if (s[i+1]=='*') cnt += (s[i]<'3'? ((s[i]=='1'? 9 : 6) * ways(s,i+2))%mod :0) ;
                else {
                    int d = (s[i]-'0') * 10 + s[i+1]-'0';
                    cnt += ((d<27)?  ways(s,i+2): 0) ;
                }
            } 
        
        }
        return dp[i] = cnt %mod;
    }
};
*/
/*
* - 0-9
*0-6 = 2
*7=1
*/