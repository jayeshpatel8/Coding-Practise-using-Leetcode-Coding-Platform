class Solution {
public:
    int maxJump(vector<int>& stones) {
        int ans = stones[1];
        // max (to cover max possible stone) and min(for allowing optimal return path) jump len should be 2
        for (int i=2; i<stones.size(); i++){
            ans = max(ans, stones[i] - stones[i-2]);
        }
        return ans;
    }
    int maxJump2(vector<int>& stones) {
         
        int l=2,   ans = INT_MAX , N = stones.size() , r = stones[N-1];
        //if (N==2) return r;
        auto check = [&](int m)->bool{
            vector<bool> vis (N);
            int start = 0 , end = stones[N-1] , next = start+m , t= 0;
            for (int i=1; i<N; i++){
                int j=i;
                 t=0;
                for ( ;j<N && stones[j] <= next; j++){
                    if (vis[j]) continue;
                    t = j;
                }
                if (t==0) return false;
                vis[t]=true;
                i=j-1;
                next = stones[t] + m;
            }
             start = 0 , end = stones[N-1] , next = start+m , t= 0;
            vis[N-1]=false;
            for (int i=1; i<N; i++){
                int j=i;
                t=0;
                for (; j<N && stones[j] <= next; j++){
                    if (vis[j]) continue;
                    t = j;
                }
                if (t==0 ) return false;
                vis[t]=true;
                i=j-1;
                next = stones[t] + m;
            }
            return true;
        };
        while (l<=r){
            int mid = l + (r-l)/2;
            if (check(mid)){
                ans=  mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
    
};