class Solution {
public:
    vector<int> uf;
    int find(int i){
        return uf[i] < 0 ? i : uf[i] = find(uf[i]);
    }
    void join(int a, int b){
        int pa = find(a)  , pb  = find(b);
        if (pa != pb){
            if (uf[pa]< uf[pb]) swap(pa,pb);
            uf[pb] += uf[pa];
            uf[pa]=pb;
        }
    }
    int makeConnected(int n, vector<vector<int>>& conn) {
        uf.resize(n,-1);
        int extra=0;
        for (auto & e : conn){
            if (find(e[0])== find(e[1]))
                extra++;
            else
                join(e[0],e[1]);
        }
        int cc =  count_if(begin(uf),end(uf),[](int a){return a< 0;})  ;
        return cc -1 > extra ? -1 : cc -1;
    }
};