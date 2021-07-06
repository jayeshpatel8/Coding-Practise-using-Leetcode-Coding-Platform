#define MOD(a) (a)%mod
class Solution {   
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int l=0;
        int r =  min_element(begin(paths),end(paths),
                [](const auto& p1, const auto & p2){
                        return p1.size() < p2.size();
                })->size();        
        const uint64_t d = 100003, mod = 1e11+3 ;
        while (l<r){
            int m = ( l+r+1) >> 1;
            unordered_set<uint64_t> common;
            uint64_t hash,d0=1,  hash0;            
            for (int i=0;  i<paths.size() && (i == 0 || !common.empty()); i++){
                hash=0;
                unordered_set<uint64_t> common2;
                for (int j=0; j<paths[i].size(); j++){
                    hash = MOD(hash * d + paths[i][j]);
                    if(j >= m)
                        hash = MOD(mod + hash - MOD(d0 * paths[i][j-m])) ;
                    else if (i==0)
                        d0 = MOD(d0 *d);                        

                    if (j>=m-1 && (i==0 || common.count(hash)))
                        common2.insert(hash);                        
                }
                swap(common,common2);
            }

            if (common.empty()) 
                r = m - 1;
            else 
                l = m ;
        }

        return l ;
    }
};

/*
3 = 2
l=2 
*/