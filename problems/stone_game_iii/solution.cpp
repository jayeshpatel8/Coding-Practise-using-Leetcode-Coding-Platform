class Solution {
public:
    string stoneGameIII(vector<int>& V) {
        int N = V.size();
        vector<int> dp(N+1);
        for (int i = N-1; i>=0; i--){
            int ans = INT_MIN, sum=0;
            for (int j=i; j< N && j<i+3 ; j++){
                sum +=V[j];
                ans = max(ans, sum - dp[j+1]); 
            }
            dp[i] = ans;
        }       

        return dp[0] == 0 ? "Tie" : (dp[0] > 0 ? "Alice" : "Bob"); 
    }    
    /**
    int dp[50000];
    string stoneGameIII(vector<int>& V) {
        for (int i =0; i<V.size(); i++)dp[i] =10000000;
        play(V,0);

        return dp[0] == 0 ? "Tie" : (dp[0] > 0 ? "Alice" : "Bob"); 
    }
    int play(vector<int>& V, int i){
        if(i>=V.size()) return 0;
        if(dp[i] != 10000000) return dp[i];
        int ans = INT_MIN, sum=0;

        for (int j=i; j<V.size() && j<i+3 ; j++){
            sum +=V[j];
            ans = max(ans, sum - play(V,j+1));            
        }
        return dp[i] = ans;
    }
    */
};