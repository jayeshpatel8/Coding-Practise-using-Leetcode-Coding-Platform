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

};