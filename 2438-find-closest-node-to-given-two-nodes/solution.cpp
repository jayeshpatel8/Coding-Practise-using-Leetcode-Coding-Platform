class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int N =  edges.size();
        vector<int> dist(N,-1);        
        int ans=INT_MAX, distance=0;       
        auto bfs = [&](int node, vector<int> & di){
            while (1)
            {
                di[node] = distance++;
                int v = edges[node];
                if (v==-1 || di[v] > -1) break;
                node=v;
            }
        };
        //bfs from node1
        bfs(node1, dist);
        // bfs from node2
        distance=0;
        vector<int> dist2(N,-1);
        bfs(node2, dist2);
        int node = -1;
        for (int i=0; i<N; i++)
            if (dist[i]>=0 && dist2[i]>=0 ){
                auto best = max(dist[i],dist2[i]);
                if (best < ans ) ans = best, node=i;
            }

        return node;
    }
};
