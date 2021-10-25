class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> G[n+1];
        vector<int> d(n+1, 10001);
        for (auto e : edges)
            G[e[0]].push_back(e[1]), G[e[1]].push_back(e[0]);
        int step=0;
        queue<int> q({n});
        d[n]=0;
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                int u =  q.front(); q.pop();                                           
                for (auto i : G[u]){
                    if (d[i] != 10001) continue;
                    d[i] = step + 1;     
                    q.push(i);
                }
            }
            step++;
        }        
        
        q.push(1);
        int min_step = d[1] + 2;
        bool done =true;
        while(!q.empty() &&  done){
            int sz = q.size();
            
            while(sz-- && done){
                int u =  q.front(); q.pop();                                           
                for (auto i : G[u]){
                    if (d[i] == d[u]) {
                        min_step--; done=false; break;
                    }
                    if (d[i] == d[u] - 1) {
                        q.push(i);   
                    }
                }
            }
        }     
        return count(min_step, time, change);
    }
    int secondMinimum2(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> G[n+1];
        vector<int> minSteps(n+1, 10001);
        for (auto e : edges)
            G[e[0]].push_back(e[1]), G[e[1]].push_back(e[0]);
        int step=-1;
        queue<int> q({1});
        while(!q.empty() && ++step <= minSteps[n] + 1){
            int sz = q.size();
            
            while(sz--){
                int u =  q.front(); q.pop();
                if (step == minSteps[u] || step > minSteps[u] + 1) continue;
                minSteps[u] = min(minSteps[u], step);
                if (u == n && step > minSteps[n] ) return count(step,time,change);
                for (auto i : G[u]){
                    q.push(i);
                }
            }
        }
        return count(minSteps[n]+2,time,change);
    }
    int count(int step, int time, int change){
        int ans = 0;
        while(--step){
            ans +=time;
            if ((ans /change) % 2){
                ans += change - (ans %change ) ;
            }
        }
        return ans+time;
    }
};