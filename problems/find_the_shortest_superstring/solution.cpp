class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> graph(n,vector<int>(n,0));
        
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                graph[i][j] = overlap(A[i],A[j]);                
                graph[j][i] = overlap(A[j],A[i]);             
            }
        }
        vector<vector<int>> dp(1<<n,vector<int>(n, INT_MAX));
        vector<vector<int>> path(1<<n,vector<int>(n));
        int min=INT_MAX,last=-1;
        for (int i=1; i < (1<< n) ; i++){
//            memset(dp[i]
            for (int j=0; j<n; j++){
                if((i & 1<<j) > 0 ){
                    int prev = i -  (1<<j);
                    if (prev==0)
                        dp[i][j] = A[j].length();
                    else{
                        for (int k=0; k<n; k++){
                            if (dp[prev][k] < INT_MAX && dp[prev][k] + graph[k][j] < dp[i][j]){
                                dp[i][j] = dp[prev][k] + graph[k][j] ;
                                path[i][j] = k;
                            }
                        }
                    }
                }
                if (i == (1<< n)-1 && dp[i][j] < min) {
                    min = dp[i][j];
                    last = j;
                }
            }
        }
        
        int cur = (1 << n) - 1;
        stack<int> st;
        while(cur>0){
            st.push(last);
            int temp = cur;
            cur -= (1<<last) ;
            last = path[temp][last];
        }
        int i = st.top();
        string ans=A[i];st.pop();
        while(!st.empty()){
            int j = st.top(); st.pop();
            ans += A[j].substr(A[j].length()-graph[i][j]) ;
            i = j;
        }
        
        return ans;
    }
    
    int overlap(string a, string b){
/*        int len1 = a.length(), len2 = b.length();
        int ans=0;
        
        for (int i = 1 ; len1-i>=0 && i<=len2; i++){
            if (a.substr(len1-i,i) == b.substr(0,i))
                ans= i;
        }
        */
     for (int k=min(a.size(), b.size()); k>=0; k--)
        {
            if (a.substr(a.size()-k)==b.substr(0,k))
                return b.size()-k;
        }        
        return b.size();
        //return len2 - ans;
    }
};