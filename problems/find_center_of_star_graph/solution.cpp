class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indegree(n+2);
        
        for(auto e : edges){
            indegree[e[0]]++;indegree[e[1]]++;
            if(indegree[e[0]]>1 ) return e[0];
            if(indegree[e[1]]>1 ) return e[1];
        }
        return 0;
    }
};