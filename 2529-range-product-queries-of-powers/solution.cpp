class Solution {
public:
int mod = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        /*
        15 = 1111        
        */    
        vector<size_t> pow2{1};
        for (int i=0; i<31;i++){
            if (n & (1u<<i)){
                pow2.push_back((pow2.back()* (1ull<<i))%mod );
            }
        }

        vector<int> ans;
        
        for (auto s : queries){
            auto p = (pow2[s[1]+1] * modinv( pow2[s[0]],mod - 2)%mod);
            ans.push_back(p);
        }
        return ans;
    }
    size_t modinv(size_t x, size_t y ){
        
        if (y==0) return 1;
        long n = modinv(x,y/2) %mod;
        n =  (n* n )%mod;
        return y&1 ? (x * n)%mod : n;
    }

};
