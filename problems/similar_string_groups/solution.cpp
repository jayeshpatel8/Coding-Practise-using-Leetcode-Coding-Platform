class Solution {
public:
    vector<int> uf;
    int find (int i){ return uf[i] < 0 ? i : uf[i] = find(uf[i]);}
    void connect(int i, int j){
        int pi = find(i), pj = find(j);
        if (pi != pj)
            uf[pi]=pj;
    }
    int numSimilarGroups(vector<string>& strs) {
         int N = strs.size();
        uf.resize(N,-1);
        for ( int i =0; i<N; i++){
            for (int j=i+1; j<N; j++){
                if (match(strs[i],strs[j])){// matches
                    connect(i,j);
                }                
            }
        }
        return (int)count(begin(uf),end(uf),-1);
    }
    bool match(string& i, string & j){
        int l=0,cnt=0;
        for (; l<i.size();  l++){
            if (i[l] != j[l] && ++cnt > 2) 
                return false;
        }
        return true;
    }
};