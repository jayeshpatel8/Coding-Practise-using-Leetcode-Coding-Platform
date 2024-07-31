class Solution {
public:
    int dp[1001]={};
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {       
        int n = books.size();
       for ( int i = n-1; i>=0; i--){
           int w =0,h = 0;
           dp[i]=INT_MAX;
           for (int j=i;  j<n; j++){
               h = max(h, books[j][1]);
               w +=  books[j][0];
               if (w <= shelfWidth)
                dp[i] = min(dp[i], dp[j+1]+h);
               else
                   break;
           }
       } 
        return dp[0];
    }
};
