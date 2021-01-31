class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        vector<int> res;
        int ncr[10014][14]={1};
        for (int n=1; n<10014; n++){
            for (int r=0; r<14 ; r++)
                ncr[n][r]  =  r==0 ? 1: (ncr[n-1][r-1]+ncr[n-1][r]) %1000000007;
        }
        
        for (auto q  : queries){
            int n = q[0],p=q[1];
            vector<int> primefactor;
            
            // get the prime factor
            for (int i=2; i*i<=p; i++)
            {
                int cnt=0;
                while(p%i == 0) cnt++,p/=i;
                
                if (cnt) {primefactor.push_back(cnt); }
            }
            if (p!=1){primefactor.push_back(1);}

            uint64_t ans=1;
            // get combinations n+r-1 choose r
            for (auto r : primefactor){
                ans = (ans * ncr[n+r-1][r]) % 1000000007;
            }
            res.push_back(ans);
        }
        return res;
    }
};