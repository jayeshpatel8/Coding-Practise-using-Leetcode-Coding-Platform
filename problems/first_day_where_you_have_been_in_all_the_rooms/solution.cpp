class Solution {
public:
    int dp[100001]={};
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
		for (int i = 1; i < nextVisit.size(); i++) {
/*
            dp[i] = (dp[i - 1]  // to reach i-1, only way to reach  i as per problem constraint
                     + (long)1  // to reach nextVisit[i - 1] 
                     + dp[i-1] - dp[nextVisit[i - 1]] // to reach back to i-1 from nextVisit[i - 1] to make i-1 event
                     + 1 // i-1 to i
                     + 1000000007) % 1000000007;
                     */
            dp[i] = ((long)2 * dp[i - 1]  - dp[nextVisit[i - 1]] + 1000000009) % 1000000007; // check above comment 
            
		}
		return dp[nextVisit.size() - 1];
    }
};