class Solution {
public:
    int color[50][50][3]={};
    int degree[50][50][3]={};
    int catMouseGame(vector<vector<int>>& graph) {
        int N = graph.size();
        int DRAW = 0, MOUSE=1, CAT=2;
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                degree[i][j][1] = graph[i].size();
                degree[i][j][2] = graph[j].size();
                for (auto c : graph[j]){
                    if (c ==0) {
                        degree[i][j][2]--;
                        break;
                    }
                }
            }
        }
        queue<vector<int>> q;
        for (int i=0; i<N; i++){
            for (int t=1; t<=2; t++){
                color[0][i][t]=MOUSE;
                q.push({0,i,t,MOUSE});
                if (i > 0){
                    color[i][i][t]=CAT;
                    q.push({i,i,t,CAT});
                }
            }
        }
        while(!q.empty()){
            auto  u = q.front(); q.pop();
            int i = u[0], j = u[1], t = u[2], w = u[3] ;// w = winner;
            
            for ( auto &v : parents(graph,i,j,t) ){
                int i2 = v[0], j2 = v[1], t2 = v[2];
                
                if (color[i2][j2][t2] == DRAW){
                    if (t2 == w){
                        color[i2][j2][t2] = w;
                        q.push({i2,j2,t2,w});
                    }
                    else{
                        degree[i2][j2][t2]--;
                        if (degree[i2][j2][t2]== 0){
                            color[i2][j2][t2] = 3-t2;
                            q.push({i2,j2,t2,3-t2});    
                        }

                    }
                }
            }
        }
        return color[1][2][1];
    }
    vector<vector<int>> parents(vector<vector<int>>& graph, int m, int c, int t){
        vector<vector<int>>  ans;
        if (t==1){
            for (auto &c2 : graph[c]) 
                if (c2 > 0) ans.push_back({m,c2,3-t});
        }
        else{
            for (auto &m2 : graph[m]) 
                ans.push_back({m2,c,3-t});
        }
        return  ans;
    }
};