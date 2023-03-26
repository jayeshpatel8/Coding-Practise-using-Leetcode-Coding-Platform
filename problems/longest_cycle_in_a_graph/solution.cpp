class Solution {
public:

    int longestCycle(vector<int>& edges) {
        int ans = -1;

        vector<int> dist(edges.size(),0);
        for (int i=0,di=0;i<edges.size(); i++){
            int j = i, d=di;
            while (j!= -1 && !dist[j]){
                dist[j]=di++;
                j=edges[j];
            }
            if (j!=-1 && dist[j] >= d ){
                ans =max(ans, di-dist[j]);
            }
        }
        return ans;
    }

};