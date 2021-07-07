class Solution {
public:
    int vis[301][301];
    int kthSmallest(vector<vector<int>>& matrix, int K) {
        
        int N = matrix.size();
        
        int ans ;
        if (K >= N*N/2){
            // end                        
            priority_queue<pair<int, pair<int,int>>> pq;
            pq.push({matrix[N-1][N-1],{N-1,N-1}});
            K = N*N-K;
         
            while(K--){
                pair<int,int> p = pq.top().second;pq.pop();
                int i = p.first, j= p.second;
                if (i!=0 && vis[i-1][j]==0)
                    pq.push({matrix[i-1][j],{i-1,j}} ), vis[i-1][j]=1;
                if (j!=0 && vis[i][j-1]==0)
                    pq.push({matrix[i][j-1],{i,j-1} }), vis[i][j-1]=1;
               
                
            }
        
            ans = pq.top().first;
        }
        else {
            // start
            priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
            pq.push({matrix[0][0],{0,0}});
            
            while(--K){
                pair<int,int> p = pq.top().second;pq.pop();
                int i = p.first, j= p.second;
                if (i!=N-1 && vis[i+1][j]==0)
                    pq.push({matrix[i+1][j],{i+1,j} }),vis[i+1][j]=1;
                if (j!=N-1 && vis[i][j+1]==0)
                    pq.push({matrix[i][j+1],{i,j+1} }),vis[i][j+1]=1;
                
            }
            ans = pq.top().first;
        }
        return ans;
    }
};