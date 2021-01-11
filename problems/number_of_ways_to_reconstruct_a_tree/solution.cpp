
class Solution {
public:

    int checkWays(vector<vector<int>>& pairs) {
        if (pairs.size()==1) return 2;
        
        unordered_map<int,bitset<500>> graph;
        for (auto &i :pairs){
            --i[0];--i[1];
            graph[i[0]][i[1]]=1;
            graph[i[1]][i[0]]=1;
        }
        int root=0;
        for (auto& [node , node_set] : graph){
            node_set[node]=1;
             if (node_set.count() == graph.size()) 
                root = 1;
        }
        
        if (root==0) return 0;
        
        bool multiple=false;
        for (auto i :pairs){
            auto nodes_union = graph[i[0]] | graph[i[1]];
            bool node_1 = nodes_union == graph[i[0]];
            bool node_2 = nodes_union == graph[i[1]];
            if (!(node_1 | node_2) ) return 0;
             multiple |=(node_1 && node_2 );
        }
        
        if (multiple) return 2;
        return 1;
    }

};

