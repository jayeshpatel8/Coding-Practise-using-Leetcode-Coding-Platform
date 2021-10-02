class Solution {
public:
    int N;
    unordered_map<string,int> dp;
    int maxConsecutiveAnswers(string a, int k) {
        N = a.size();
        int cntT =0, cntF=0, ans= 0;
        for ( int i=0 , j = 0; i<N; i++){
            if (a[i] == 'T') cntT++;
            else cntF++;
            if (cntT>k && cntF>k){
                ans =max (ans, cntT+cntF-1);
                while(cntT>k && cntF>k){
                    if (a[j++] == 'T') cntT--;
                    else cntF--;                    
                }
            }
            else  continue;            
        }
        return ans =max (ans, (cntT+cntF));
        //if(k==N) return N;
        //return dfs(a, 0,k);
    }
    int dfs(string & a, int i, int k){
        if ( k<1 || i>=N ) {
            return cnt(a);
        }
        string key = to_string(k) + a;
        if (dp.count(key)) return dp[key];
        int ans = dfs(a, i+1, k);       
        int t = a[i];
         a[i] =  (t == 'F') ? 'T' : 'F';
        ans =max(ans, dfs(a, i+1, k-1));
        a[i] = t;
        return dp[key] = ans;
    }
    int cnt(string & a){
        int p = a[0], c = 1  ,ans = 1;
        for ( int i=1; i<N; i++){
            if (p == a[i]){
                c++;
            }
            else{
                ans= max(ans, c);
                p = a[i]; c= 1;
            }
        }
        return max(ans, c);
    }
};