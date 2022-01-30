
class Solution {
public:
    vector<int> uf , size;
    int find( int i){
        return uf[i]<0? i : uf[i] = find(uf[i]);
    }
    void connect( int i, int j){
        int pi = find(i) , pj = find(j);
        if (pi !=  pj){
            if (size[pi]  > size[pj]){
                uf[pj]=pi;
                size[pi] +=size[pj];
            }
            else{
                uf[pi]=pj;
                size[pj] +=size[pi];
            }
        }
    }
    vector<int> groupStrings(vector<string>& A) {
        int N = A.size();
        uf.resize(N,-1);
        size.resize(N,1);
        unordered_map<int, int> m, ReplaceMap;
		m.reserve(N);
        for (int i = 0; i < N; ++i) {
            int mask = 0;
            for (char c : A[i]) mask |= 1 << (c - 'a'); 
            for (int j = 0; j < 26; ++j) {
                if (mask & (1<<j)) { 
                    int del = mask ^ (1 << j); 
                    if (m.count(del)) connect(i, m[del]); 
                    if (ReplaceMap.count(del)) connect(i, ReplaceMap[del]);
                    else ReplaceMap[del] = i;
                } else {
                    int add = mask | (1 << j);
                    if (m.count(add)) connect(i, m[add]);
                }
            }
            m[mask] = i;
        }

        return {(int)count(begin(uf),end(uf),-1), *max_element(begin(size),end(size))};
    }
};