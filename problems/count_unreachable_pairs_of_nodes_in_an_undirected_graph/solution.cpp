class Solution {
public:
    vector<int> uf ,size;
    int find(int a){
        return uf[a] <0 ? a : uf[a] = find(uf[a]);
    }
    
    void merge(int a, int b){
        int pa= find(a), pb =find(b);
        if (pa != pb){
            if (size[pa] < size[pb])
                uf[pb]=pa, size[pa] += size[pb];
            else
                uf[pa]=pb , size[pb] += size[pa];
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        uf.resize(n, -1);
        size.resize(n, 1);
        
        for (auto &e : edges)
                merge(e[0],e[1]);
        
        long long ans = 0;
        for (int i=0; i<n; i++)   
            ans += (n - size[find(i)]);

        return ans / 2;
    }
};