class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        bool vis[2001]={};
        int ans = 0;
        sort(begin(tasks),end(tasks),[](auto &a, auto &b){ return a[1] < b[1];});
        for (auto &i : tasks){
            for ( int j=i[1]; j>=i[0]; j--){
                if (vis[j]){
                    i[2]--;                    
                }
            }
            if (i[2]>0){
                for ( int j=i[1]; i[2]>0; j--){
                    if(!vis[j]){
                        vis[j]=1; i[2]--;ans++;
                    }
                }
            }
        }
        return ans ;
    }
};