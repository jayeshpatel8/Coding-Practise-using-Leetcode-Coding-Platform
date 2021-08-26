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
    /*
    int dp[1001][1001];
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
       memset(dp,-1, sizeof(dp));    
        return dfs(books, shelfWidth, 0, 0,0);
    }        
    int dfs(vector<vector<int>>& books, int shelfWidth, int i, int w, int h){
        if(i == books.size()) return h;

        
        if(dp[i][w] != -1) return dp[i][w];
        int ans = INT_MAX;
        
        if (w + books[i][0]<= shelfWidth)
            ans = min(ans,  dfs(books, shelfWidth, i+1, w + books[i][0],max(h,  books[i][1])));
        
            ans = min(ans,  h + dfs(books, shelfWidth, i+1, books[i][0], books[i][1]));
        
        return dp[i][w] = ans;
        
    }*/
};