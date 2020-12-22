class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
     unordered_map<int,int> m;
        
        for (auto i : deck) ++m[i];
        int g=0;
        for (auto [i,j]: m) {
            g = gcd(g, j);
            if (g < 2) return false;
        }
        return true;
        #if 0
        if ( mi<2) return false;
        int r=true;
        for (int k=mi; mi>=2; mi--){
            if (deck.size()% mi != 0) {r=false;continue;}
            r=true;
            for (auto [i,j]: m) if (j != mi && j%mi != 0) r= false;
            if (r) break;
        }
        
        return r;
        #endif
    }
    int gcd(int a , int b){
        if (a==0) return b;
        return gcd(b%a, a);
    }
};