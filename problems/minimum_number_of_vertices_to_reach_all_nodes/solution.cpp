class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ind(n);
        for ( auto & e : edges)
            ind[e[1]]++;
        vector<int> ret;
        for (auto i=0; i<n;i++) 
            if (ind[i]==0) 
                ret.push_back(i);
        return ret;        
    }
};