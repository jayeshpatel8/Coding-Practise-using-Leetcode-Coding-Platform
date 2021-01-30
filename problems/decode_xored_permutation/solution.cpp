class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size();
        vector<int> perm(n+1,0);         
        perm[0] = ((n+2)>>1 )% 2;

        
        for (int i=1;i<n;i+=2 ){
            perm[0] ^= encoded[i];
        }
        
        
        for (int i=1; i<=n; i++){
            perm[i] =encoded[i-1]^perm[i-1]; 
        }
        return perm;
    }
};