

class Solution {
public:
    vector<int> uf[3],size[3];
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        //sort(rbegin(edges),rend(edges));
        uf[1].resize(n+1,-1);
        uf[2].resize(n+1,-1);
        size[1].resize(n+1);
        size[2].resize(n+1);        
        int rem=0;
        for (auto & e : edges)
            if (e[0]==3)
                rem += connect(e);
        for (auto & e : edges){
            if (e[0] != 3) rem += connect(e);
        }
        if (count(begin(uf[1]),end(uf[1]),-1) != 2 || count(begin(uf[2]),end(uf[2]),-1) != 2 )
           return -1;
        return rem;
    }
    int find(int e, int i){
        return uf[e][i] < 0 ? i : uf[e][i] = find(e,uf[e][i]);
    }
    bool check(vector<int> &e){
        if (e[0] == 3)
            return (find(1,e[1])==find(1,e[2])  && find(2,e[1])==find(2,e[2]) );
        else
            return (find(e[0],e[1])==find(e[0],e[2]));
    }
    int connect(vector<int> &e){
        if (e[0] == 3){
            if ((find(1,e[1])==find(1,e[2])  && find(2,e[1])==find(2,e[2]) ))return 1;
            for (int i=1; i<=2; i++){
                int pi=find(i,e[1]), pj=find(i,e[2]);
                if (pi != pj){
                    if (size[i][pi] > size[i][pj])
                    {size[i][pi]+= size[i][pj]; uf[i][pj]=pi;}
                    else
                        size[i][pj]+= size[i][pi], uf[i][pi]=pj;
                }            
            }
            return 0;
        }
        else{
            int pi=find(e[0],e[1]), pj=find(e[0],e[2]);
            if (pi != pj){
                if (size[e[0]][pi] >  size[e[0]][pj])
                    size[e[0]][pi] += size[e[0]][pj], uf[e[0]][pj]=pi;
                else
                    size[e[0]][pj] += size[e[0]][pi], uf[e[0]][pi]=pj;
                return 0;
            }
            return 1;
        }
    }
};
