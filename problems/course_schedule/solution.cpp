class Solution {
public:

    bool canFinish(int n, vector<vector<int>>& pre) {
        if (pre.size() < 1) return true;
        vector<int> graph[n] , indegree(n,0);
        
  
        for ( int i=0; i< pre.size(); i++){
            graph[pre[i][0]].push_back(pre[i][1]);
            indegree[pre[i][1]]++;
        }
        queue<int> q;
        for ( int i=0; i< n; i++)
            if (indegree[i]==0) q.push(i);
        int count=0;
        while(!q.empty()){
            int qs = q.size();
            count +=qs;
            
            for (int i=0; i<qs; i++ ){
                int j = q.front();
                q.pop();
                for (auto u : graph[j])
                    if (--indegree[u] == 0) q.push(u);
            }
        }
                
        return count==n;
    }
};