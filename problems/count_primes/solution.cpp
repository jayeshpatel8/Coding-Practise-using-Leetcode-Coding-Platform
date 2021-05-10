class Solution {
public:

    int countPrimes(int n) {
        int cnt=0;
        vector<int> p(n+1,1);
        
        uint64_t ceil_ = ceil(sqrt(n));

        for (int i=2;  i<n; i++ ){
            if (p[i]==0 )  continue;
            cnt += 1;
            if (i>= ceil_) continue;
            for (int j=i+i; j<=n; j+=i)
                p[j]=0;            
        }
            
        return cnt;
    }
};