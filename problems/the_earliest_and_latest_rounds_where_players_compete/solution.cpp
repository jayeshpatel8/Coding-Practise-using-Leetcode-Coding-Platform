class Solution {
public:
    int vis[28][28][28] = {};
    int minr = INT_MAX, maxr = INT_MIN;
    int N ;
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        N=n;
        dfs((1<<n)-1,1,0,N-1,firstPlayer-1,secondPlayer-1,firstPlayer-1,secondPlayer-firstPlayer-1,n-secondPlayer);
        return {minr,maxr};
    }
    void dfs(int mask, int round, int i, int j, int f, int s, int l, int m, int r){
        if (i>=j) 
            dfs(mask,round+1,0,N-1,f,s,l,m,r);
        else if (( mask & (1<<i)) == 0){
            while (( mask & (1<<i)) == 0 && (i<j)) i++;
            dfs(mask,round,i,j,f,s,l,m,r);
        }
        else if ((mask & (1<<j))==0){
            while (( mask & (1<<j)) == 0 && (i<j)) j--;
            dfs(mask,round,i,j,f,s,l,m,r);
        }
        else if (i== f && j ==s){
            minr = min (minr, round);
            maxr = max (maxr, round);
        }else if (!vis[l][m][r]) {
            vis[l][m][r] =1;
            if (i!=f && s!=i)
                dfs(mask ^ (1 << i),round,i+1,j-1,f,s,l - (i<f),m - (i>f && i<s),r- (i>s));
            
            if (j!=f && j!= s)
                dfs(mask ^ (1 << j),round,i+1,j-1,f,s,l - (j<f),m - (j>f && j<s),r- (j>s));
        }
    }
};