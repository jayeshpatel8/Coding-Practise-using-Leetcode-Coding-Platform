class Solution {
public:
    int countTriples(int n) {
        int ans=0,nn = n*n;
        for ( int i=3; i<=n; i++){
            int aa = i*i,c=0;
            for (int j=i,cc=aa+j*j; c<n; ++j,cc=aa+j*j ){
                 c = sqrt(cc);
                ans += (c*c == cc);
            }
        }
        return ans*2;
    }
};