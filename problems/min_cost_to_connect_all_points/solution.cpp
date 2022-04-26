class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        //prim optimized
        int N = p.size();
        vector<int>  minDist(N,INT_MAX);
        vector<bool> inMst(N);
        int e=0 , cost = 0;
        minDist[0]=0;
        while (e<N){
            int curN = -1;
            int curE = INT_MAX;
            for (int i=0; i<N; i++){
                if (!inMst[i] && curE > minDist[i]){
                    curE = minDist[i];
                    curN = i;
                }
            }
            cost +=minDist[curN];
            inMst[curN]=true;
            e++;
            for (int i=0; i<N; i++){
                int weight = abs(p[i][0] - p[curN][0]) + abs(p[i][1] - p[curN][1]);
                if (!inMst[i] && minDist[i] > weight){
                    minDist[i] = weight;
                }
            }
        }
        return cost;
    }
    vector<int> uf;
    vector<int> size;
    int minCostConnectPoints2(vector<vector<int>>& points) {
        int N = points.size();
        uf.resize(N,-1);
        size.resize(N);
        vector<array<int,3>> e;
        for (int i=0; i<N; i++){
            auto x1 = points[i][0], y1 = points[i][1];
            for (int j=i+1; j<N; j++){                
                auto x2 = points[j][0], y2 = points[j][1];
                auto d = abs(x1-x2) + abs(y1-y2);
                e.push_back({d,i,j});
            }
        }
        
        sort(begin(e),end(e));
        int ans = 0;
        for (auto &i : e){
            if (find(i[1]) == find(i[2])) continue;
            ans +=i[0];
            join(i[1],i[2]);
        }
        return ans;
    }
    int find(int i){
        return uf[i]==-1 ? i : (uf[i] = find(uf[i]));
    }
    void join(int i, int j){
        auto pi = find(i), pj = find(j);
        if (pi != pj){
            if (size[pi] < size[pj]){
                uf[pj]= pi;
                size[pi] += size[pj];
            }
            else
                uf[pi]= pj, size[pj] += size[pi];
        }
    }
};