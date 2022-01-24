class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& T) {
        int h = 0;
        vector<int> sub[n+1];
        for ( int i=0; i<n; i++){
            int m = manager[i];
            if ( m != -1){
                sub[m].push_back(i);
            }
            else
                h = i;
        }
        
        queue<array<int,2>> q;
        q.push({h,T[h]});
        int ans=0;
        while (!q.empty()){
            auto [i,t] = q.front(); q.pop();
            ans= max(ans,t);
            for (auto  j : sub[i]){
                q.push({j,T[j] + t});
            }
        }
        return ans;
    }
};