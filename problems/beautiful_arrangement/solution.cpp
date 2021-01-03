class Solution {
public:
    int p=0;
    
    int countArrangement(int n) {
        
        vector<int> vis;
        for (int i=0; i<=n;i++) 
            vis.push_back(i);        
        cnt(n,vis);
        return p;
    }
    void cnt(int n,vector<int> vis){
        if (n<1) {p++ ; return ;}
      
        
        for ( int j=n; j>=1; j--){
            if ((n%vis[j]==0 || vis[j]%n==0)){
                swap(vis[j],vis[n]);
                cnt(n-1,vis);
                swap(vis[j],vis[n]);
            }
            
        }
        return ;
    }
};