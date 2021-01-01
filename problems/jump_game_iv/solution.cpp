class Solution {
public:
    unordered_map<int, vector<int>> m;
    
    int minJumps(vector<int>& arr) {
        const int N = arr.size();
        if (N<=1) return 0;
        for (int i=0; i<N; i++ ){
            m[arr[i]].push_back(i);
        }
        
        
        // BFS
        queue<int> q;
        vector<bool> vis(N,false);
        q.push(0);
        int step=-1;
        vis[0]=true;
        while(!q.empty()){
            int qs = q.size();
            step++;            
            
            while(qs--){
                int i = q.front();q.pop();
                if (i + 1 == N) return step;
                if (i-1>=0 && !vis[i-1]) q.push(i-1),vis[i-1]=true;;
                if (i+1<N && !vis[i+1]) q.push(i+1),vis[i+1]=true;;
                for (auto j : m[arr[i]]) 
                    if (!vis[j])
                        q.push(j),vis[j]=true;;
                m[arr[i]].clear();
            }
        }
        
        return step;
    
    }
};