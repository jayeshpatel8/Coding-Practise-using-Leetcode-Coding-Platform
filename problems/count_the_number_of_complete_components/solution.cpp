class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<long,int> cnt;
        vector<long> graph(n);
        for (auto &i : edges){
            int u = i[0], v = i[1];
            graph[u] |= 1ul<< v;
            graph[u] |= 1ul<< u;
            graph[v] |= 1ul<< u;
            graph[v] |= 1ul<< v;
        }   
        int ret = 0;
        for (auto i=0;i <n;i++) {
            if (graph[i]==0)
                ret++;
            else cnt[graph[i]]++;
        }
        
        for (auto &[k,v] : cnt) 
            if (getbits(k)==v)
                ret += 1;
        
        
        return ret;
    }
    int getbits(long n){
        int ret = 0;
        while (n)
            ret++, n &=n-1;
        return ret;
    }
};