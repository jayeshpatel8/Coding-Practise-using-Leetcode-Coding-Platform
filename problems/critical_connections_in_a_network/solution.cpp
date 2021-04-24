class Solution {
public:
    vector<int> visited, low_time, visit_time;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        vector<vector<int>> graph(n+1);
        visited.resize(n,0);
        low_time.resize(n,0);
        visit_time.resize(n,0);
        for (auto i : connections){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }  
        
        dfs(graph, 0,-1,ans);
        return ans;
    }
    void dfs (vector<vector<int>> &graph , int i, int parent , vector<vector<int>> &ans ){
        static int time=0;
        visited[i]=true;
         visit_time[i]=low_time[i]=time++;
        for (auto n : graph[i]){
            if(n == parent) continue;
           
            if (!visited[n]){
                
                dfs(graph, n,i,ans);
                
                low_time[i] = min(low_time[i], low_time[n]); 
                if (low_time[n] > visit_time[i]) ans.push_back({i,n});
            }
            else{
                low_time[i] = min(low_time[i], visit_time[n]); 
            }
                
        }
    }
};